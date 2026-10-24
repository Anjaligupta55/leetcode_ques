class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAliceMonth=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
        int arriveAliceDay=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        int leavemonthAlice=(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0');
        int leavedayAlice=(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
        int arriveBobMonth=(arriveBob[0]-'0')*10+(arriveBob[1]-'0');
        int arriveBobDay=(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
        int leavemonthbob=(leaveBob[0]-'0')*10+(leaveBob[1]-'0');
        int leavedaybob=(leaveBob[3]-'0')*10+(leaveBob[4]-'0');

        int days[] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int a1 = days[arriveAliceMonth-1] + arriveAliceDay;
        int a2 = days[leavemonthAlice-1] + leavedayAlice;
        int b1 = days[arriveBobMonth-1] + arriveBobDay;
        int b2 = days[leavemonthbob-1] + leavedaybob;

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};