codeforces 282B:
有n项任务分配给A和G两人，对于第i项任务，A报价为A[i],G报价为G[i]，符合条件A[i]+G[i]==1000。
设sumA为A总收金额，sumG为G总收金额，问有无分配方式使得abs（sumA-sumG）<=500?

在sumA=sumAll（A[i]）,sumG=0的初始状态下
推导得：sumA每减一次A[i],且G每加一次G[i],有sumA-A[i]-(sumG+G[i]) = sumA-sumG-1000,
即每次A退掉一项任务，而G接受该项任务，可使sumA与sumG之间的差距少1000.