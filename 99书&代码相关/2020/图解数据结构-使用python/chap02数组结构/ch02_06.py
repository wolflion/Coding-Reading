# 实现4*4 二维数组的转置
arrA = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
N=4
arrB = [[None] * N for row in range(N)]
print('[原设置的矩阵内容]')
for i in range(4):
    for j in range(4):
        print('%d' %arrA[i][j],end='\t')
    print()

# 进行矩阵转置操作
for i in range(4):
    for j in range(4):
        arrB[i][j]=arrA[j][i]

print('[转置矩阵的内容为]')
for i in range(4):
    for j in range(4):
        print('%d' %arrA[i][j],end='\t')
    print()  #原书这行还写错了，与第1个for对齐了。（有可能是印刷的问题）