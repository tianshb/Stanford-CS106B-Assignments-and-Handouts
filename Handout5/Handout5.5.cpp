
a)
MaxSoFar = 0
￼￼S
￼￼￼￼￼￼￼￼￼￼￼￼
￼￼
for L = 1 to N
    for U = L to N
        Sum = 0
        for I = L to U
            Sum = Sum + vec[I]
/* Sum now contains the sum of vec[L...U] */
        MaxSoFar = max(MaxSoFar, sum)

b)
MaxSoFar = 0
for L = 1 to N
    Sum = 0
    for U = L to N
        Sum = Sum + vec[U]
/* Sum now contains the sum of vec[L...U] */
    MaxSoFar = max(MaxSoFar, Sum)

c)

MaxSum(L, U, vec)
{
    /* Zero-element vector */
    if L > U
        return 0
    /* One-element vector */
        if L = U
            return max(0, vec[L])
        /* The left half of the recusion is vec[L...M], the right is
         vec[M+1...U] */
            M = (L+U)/2
        /* Find max touching the border on the left */
            SumLeft = 0
            MaxToLeft = 0
            for I = M to L /* M is more than L, so I decreases from M to L */
                SumLeft = SumLeft + vec[I]
                MaxToLeft = max(MaxToLeft, SumLeft)
            /* Find max touching the border on the right */
                SumRight = 0
                MaxToRight = 0
                for I = M+1 to U
                    SumRight = SumRight +vec[I]
                    MaxToRight = max(MaxToRight, SumRight)
                /* MaxCrossing is the maximum subvector sum which crosses the
                 border */
                    MaxCrossing = MaxToLeft + MaxToRight
                    MaxInLeftHalf = MaxSum(L, M, vec)
                    MaxInRightHalf = MaxSum(M+1, U, vec)
                    return max(MaxCrossing, MaxInLeftHalf, MaxInRightHalf)
                    }

d)
MaxSoFar = 0
MaxEndingHere = 0
for I = 1 to N
/* MaxEndingHere and MaxSoFar are accurate for X[1...I-1] */
    MaxEndingHere = max(MaxEndingHere+X[I], 0)
    MaxSoFar = max(MaxSoFar, MaxEndingHere)

