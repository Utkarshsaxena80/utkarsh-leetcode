class Solution(object):
    def maxProfit(self, prices):
        p=0
        i=0
        j=0
        while j<len(prices):
            p=max(p,prices[j]-prices[i])
            if prices[j]<prices[i]:
                i=j
            j+=1    
        return p
        