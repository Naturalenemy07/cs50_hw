//cs50 staff code from line 3 - 67 (i did change the 'void print_winner(void)' to 'string print_winner(void)'')

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
string print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();

}

//My code starting below

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
string print_winner(void)
{
    //for loop that conducts one round of bubble sort (the largest numbers will "bubble up" and appear at the end of the array)
    for (int i = 0; i < candidate_count - 1; i++)

    {
        if (candidates[i].votes > candidates[i + 1].votes)
        {
            int k = candidates[i].votes;//use third variable to store number
            candidates[i].votes = candidates[i + 1].votes;
            candidates[i + 1].votes = k;

            string c = candidates[i].name;
            candidates[i].name = candidates[i + 1].name;
            candidates[i + 1].name = c;

        }


    }

    //records the maximun number of votes a candidate/s recieved
    int max_votes = candidates[candidate_count - 1].votes;
    //printf("%d\n", max_votes);

    //prints out the candidate/s that recieved the maximun number of votes ie. winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return 0;

}
