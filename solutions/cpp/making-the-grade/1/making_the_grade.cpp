#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_student_scores;
    rounded_student_scores.reserve(student_scores.size());
    
    for(double student_score : student_scores)
        {
            rounded_student_scores.push_back(static_cast<int>(student_score));
        }
    return rounded_student_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for(int student_score : student_scores)
        {
            if(student_score <= 40)
            {
                count++;
            }
        }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int increment = (highest_score - 40) / 4;
    
    std::array<int, 4> grade_thresholds;
    grade_thresholds[0] = 41;
    for(int i = 1; i < 4; i++)
        {
            grade_thresholds[i] = grade_thresholds[i - 1] + increment;
        }
    
    return grade_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking;

    for(int i = 0; i < student_scores.size(); i++)
        {
            ranking.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
        }
    
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for(int i = 0; i < student_scores.size(); i++)
        {
            if(student_scores[i] == 100)
            {
                return student_names[i];
            }
        }
    return "";
}
