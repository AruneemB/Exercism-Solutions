#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

int vote_count(ElectionResult& electionResult)
{
    return electionResult.votes;
}

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

void increment_vote_count(ElectionResult& electionResult, int increment)
{
    electionResult.votes += increment;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

ElectionResult& determine_result(std::vector<ElectionResult>& electionResults)
{
    int winnerIndex = 0;
    int mostVotes = vote_count(electionResults[0]);
    
    for (int i = 1; i < electionResults.size(); ++i) 
    {
        if (vote_count(electionResults[i]) > mostVotes) 
        {
            mostVotes = vote_count(electionResults[i]);
            winnerIndex = i;
        }
    }
    electionResults[winnerIndex].name = "President " + electionResults[winnerIndex].name;

    return electionResults[winnerIndex];
}

}  // namespace election