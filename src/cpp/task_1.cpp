/*
 * Author:farxod
 * Date:
 * Name:
 */



class ProblemSolution {
public:
    ListNode* mergeListNodes(ListNode* listHead) {
        ListNode *currentNode=listHead->next;
        ListNode *previousNode=listHead;
        int accumulatedValue=0;
        while(currentNode!=NULL)
        {
            if(currentNode->val==0)
            {
                previousNode->val=accumulatedValue;
                if(currentNode->next!=NULL)
                    previousNode=previousNode->next;
                accumulatedValue=0;
            }
            else
            {
                accumulatedValue=accumulatedValue+currentNode->val;
            }
            currentNode=currentNode->next;
        }
        previousNode->next=NULL;
        return listHead;
    }
};