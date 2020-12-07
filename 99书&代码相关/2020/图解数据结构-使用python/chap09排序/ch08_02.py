# 改进的冒泡排序法
def showdata(data):
    for i in range(6):
        print('%3d' %data[i],end=' ')
    print()

def bubble(data):
    for i in range(5,-1,-1):
        flag = 0   #flag用来判断是否执行交换操作
        for j in range(i):
            if data[j+1] < data[j]:
                data[j],data[j+1] = data[j+1],data[j]
                flag+=1  #如果执行过交换操作，flag就不为0
            
        if flag==0:
            break

#执行完一次扫描后，判断是否执行过交换操作，如果没有交换过数据，就表示此时数组已完成排序，故可直接跳出循环
        print('第 %d 次排序:' %(6-i),end=' ')
        for j in range(6):
            print('%3d' %data[j],end=' ')
        print()  #这个又不对了，原文跟上一个print()对齐了
        print('排序后的结果为: ', end='')
        showdata(data)

def main():
    data=[4,6,2,7,8,9]
    print('改进的冒泡排序法测试用的原始数据为: ')
    bubble(data)

main()