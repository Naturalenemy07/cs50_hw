//this code is from CS50 staff; only special functions are original

#include <cs50.h>
#include <stdio.h>
#include <string.h> //i included string.h to compare strings

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct //
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
void eliminated_candidate(int voter, int preference);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    /////////////////////////////////////////////  original between these two forward slant lines
/*  This code was used to check my preferences array

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }

        printf("\n");

    }
*/
    //////////////////////////////////////////////

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


// Code below is original
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; //add this candidate's location number to the preferences matrix
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int pref = 0; //this is the first preference, will change if a candidate is eliminated.

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].eliminated == false && j == preferences[i][pref])
            {
                candidates[j].votes++;
                printf("%s: %i\n", candidates[j].name, candidates[j].votes); //used to check my vote counter //testingg////
            }
            else if (candidates[j].eliminated == true && j == preferences[i][pref]) //if the candidate is eliminated
            {
                eliminated_candidate(i, pref);

            }
        }
    }
    return;
}

// Used as a recursive function to move down the preferences of a voters choices if candidate/s is/are eliminated
void eliminated_candidate(int voter, int preference)
{
    if (candidates[preference].eliminated == false && preference + 1 == preferences[voter][preference + 1])
    {
        candidates[preference + 1].votes++;
        printf("%s: %i", candidates[preference + 1].name, candidates[preference + 1].votes); ////////testing my recursive function////
    }
    else
    {
        printf("%s: %d\n", candidates[preference + 1].name, candidates[preference + 1].votes);

        printf("%s: %d\n", candidates[preference].name, candidates[preference].eliminated);
        printf("Preference + 1: %i\n", preference + 1);
        printf("Preference array: %i\n", preferences[voter][preference + 1]);
        preference++;
        eliminated_candidate(voter, preference);
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void) // the sorting algorithm in find_min() may interfere with the tabulate algorithm
{
    int min = MAX_VOTERS + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
                printf("local min: %i\n", min);
            }
        }
    }

    printf("global min: %i\n", min);
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int counter = 0;

    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[i].eliminated == false  && candidates[i].votes == min)
        {
            counter = counter + 0;
        }
        else if (candidates[i].eliminated == false && candidates[i].votes > min)
        {
            counter++;
        }
    }

    if (counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

