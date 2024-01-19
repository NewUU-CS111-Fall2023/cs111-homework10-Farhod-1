/*
 * Author:
 * Date:
 * Name:
 */

class NetworkDelay {
public:
    int calculateDelay(vector<vector<int>>& travelTimes, int nodeCount, int startNode) {
        vector<pair<int,int>> adjacencyList[nodeCount+1];
        for(int i=0; i<travelTimes.size(); i++){
            adjacencyList[travelTimes[i][0]].push_back({travelTimes[i][1], travelTimes[i][2]});
        }
        vector<int> delayTimes(nodeCount+1, 1e9);
        set<pair<int,int>> nodeSet;
        nodeSet.insert({0, startNode});
        delayTimes[startNode] = 0;
        while(!nodeSet.empty()){
            auto currentNode = *(nodeSet.begin());
            int weight = currentNode.first;
            int node = currentNode.second;
            nodeSet.erase(nodeSet.begin());
            for(auto it: adjacencyList[node]){
                if(it.second + weight < delayTimes[it.first]){
                    delayTimes[it.first] = it.second + weight;
                    nodeSet.insert({delayTimes[it.first], it.first});
                }
            }
        }
        for(int i=1; i<nodeCount+1; i++){
            if(delayTimes[i] == 1e9){
                return -1;
            }
        }
        return *max_element(delayTimes.begin()+1, delayTimes.end());
    }
};