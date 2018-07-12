#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 100000

int numOfMeeting;
typedef struct _MEETING{
    int startTime, endTime;
}Meeting;

Meeting meeting[MAX_SIZE];

bool cmp2(const Meeting &a, const Meeting &b){
    if(a.endTime == b.endTime)
        return a.startTime < b.startTime;
    return a.endTime < b.endTime;
}

int main(void){
    cin >> numOfMeeting;
    for(int i = 0; i < numOfMeeting; i++){
        cin >> meeting[i].startTime; cin >> meeting[i].endTime;
    }

    sort(meeting, meeting+numOfMeeting,cmp2);

    int result = 1;
    Meeting comp = meeting[0];
    for(int i = 1; i < numOfMeeting; i++){
        if(meeting[i].startTime >= comp.endTime){
            result++;
            comp = meeting[i];
        }
    }

    cout << result << endl;

    return 0;
}
