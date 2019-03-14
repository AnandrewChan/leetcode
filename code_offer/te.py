import shutil
import os
path = "E:/book/offer_2"  # 文件夹目录
files = os.listdir()  # 得到文件夹下的所有文件名称
s = []
for file in files:  # 遍历文件夹
    print(file)
    if not os.path.isdir(file):
        print(file)
        if file.split('.')[1] != 'py' and len(file.split('_')) == 1:
            fo = open(file, "r")

            line = fo.readlines()[14]
            print(line.split('题')[1].split('：')[0])
            newname = line.split('题')[1].split('：')[0].split('（')[0]+'_'+file
            fo.close()
            # newname = file.split('_')[2]
            os.rename(os.path.join(path, file), os.path.join(path, newname))
            # 关闭文件


# print(s)
