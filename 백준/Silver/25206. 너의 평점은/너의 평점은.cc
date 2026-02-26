#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string subject, grade;
    double credit;
    
    double totalScore = 0.0;  // (학점 * 과목평점)의 총합
    double totalCredit = 0.0; // 학점의 총합
    
    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;
        
        if (grade == "P") continue;
        
        double gradePoint = 0.0;
        
        if (grade == "A+") gradePoint = 4.5;
        else if (grade == "A0") gradePoint = 4.0;
        else if (grade == "B+") gradePoint = 3.5;
        else if (grade == "B0") gradePoint = 3.0;
        else if (grade == "C+") gradePoint = 2.5;
        else if (grade == "C0") gradePoint = 2.0;
        else if (grade == "D+") gradePoint = 1.5;
        else if (grade == "D0") gradePoint = 1.0;
        else if (grade == "F") gradePoint = 0.0;
        
        totalScore += (credit * gradePoint);
        totalCredit += credit;
    }
    
    cout << fixed;
    cout.precision(6);
    cout << totalScore / totalCredit << "\n";
    
    return 0;
}