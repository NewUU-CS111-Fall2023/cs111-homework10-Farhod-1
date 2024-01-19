/*
 * Author:
 * Date:
 * Name:
 */
class RabbitCount {
public:
    int countRabbits(vector<int>& rabbitGroups) {
        int totalRabbits = 0;
        unordered_map<int,int> groupCountMap;
        for(auto &groupSize: rabbitGroups){
            groupCountMap[groupSize]++;
        }
        for(auto &group: groupCountMap){
            totalRabbits += ceil((float)group.second/(group.first+1))*(group.first+1);
        }
        return totalRabbits;
    }
};