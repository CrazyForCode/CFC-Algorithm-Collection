给定一串数字，求其中最大的连续和，并给出该连续和对应的起点和终点。

方法：遍历整个数组
设置st，ed，sum分别为当前遍历到i（包含num[i]），时的起点，终点和最大和。
再设置sst，sed，maxSum，分别为当前遍历到i时的起点，终点和最大和。
即用sum试水来求maxSum。

sum = max（sum+num[i],num[i]）,当sum=sum+num[i]时，st不变，ed+=1,；当sum=num[i]时，st=ed=i。