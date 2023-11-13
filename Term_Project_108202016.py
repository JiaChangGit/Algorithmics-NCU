#!/usr/bin/env python
# coding: utf-8

# In[10]:


# -*- coding: utf-8 -*-
"""
@title: ML for Chinese hand-write
@author: Jia-Chang Chang
@time: 22-6-07
"""
import os
import numpy as np
#圖表
from matplotlib import pyplot as plt
#用以載入圖檔
from PIL import Image
#用以建立線性模組
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
#CNN捲基層與池化層
from keras.layers import Conv2D, MaxPooling2D
#將Label 標籤轉為 one-hot-encoding
from keras.utils import np_utils


#資料前處理函式
def data_x_y_preprocess(datapath):
    img_row, img_col = 28, 28  #圖片大小28*28
    datapath = datapath  #資料路徑
    data_x = np.zeros((28, 28)).reshape(1, 28, 28)  #儲存圖片
    np.random.shuffle(data_x)  #打亂資料
    pictureCount = 0  #紀錄圖片數量以便reshape
    data_y = []  #紀錄label
    num_class = 10  #圖片種類有10種
    for root, dirs, files in os.walk(datapath):  #遍歷所有路境內的檔案
        for f in files:  #找出檔案
            label = int(root.split("\\")[2])  #取label
            data_y.append(label)  #將label放入data_y
            fullpath = os.path.join(root, f)  #檔案路徑
            img = Image.open(fullpath)  #開啟照片
            img = (np.array(img) / 255).reshape(1, 28, 28)  #讀照片以及正規劃且reshape
            data_x = np.vstack((data_x, img))  #處理完成後加入data_x
            pictureCount +=1  #圖片數量+1
    #刪除原先宣告的np.zeros
    data_x = np.delete(data_x, [0], 0)
    print('----- Start -----')
    #調整格式(張數, row, col, 灰階)
    data_x = data_x.reshape(pictureCount, img_row, img_col, 1)
    #將label轉成one-hot encoding
    data_y = np_utils.to_categorical(data_y, num_class)
    return data_x, data_y  #回傳所有處理好的資料



#從train_image資料夾取得資料
data_train_X, data_train_Y = data_x_y_preprocess("train_image")
#從test_image資料夾取得資料
data_test_X, data_test_Y = data_x_y_preprocess("test_image")


#建立線性執行模型，標準一層一層傳遞的神經網路叫 Sequential
model = Sequential()

#建立卷基層，filters=32，即output size層數，kernel_size(filter大小)=5*5，加入padding層，並且使用relu
#padding = 'valid' 最一開始敘述的卷積計算，圖根據filter大小和stride大小而變小
#padding = 'same'，會用zero-padding的手法，讓輸入的圖不會受到kernel map的大小影響
model.add(
    Conv2D(32, kernel_size=(5, 5), padding= 'same', activation='relu', input_shape=(28, 28, 1)))
model.add(MaxPooling2D(pool_size=(2, 2)))  #建立池化層，大小2*2，取最大值
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立卷基層，filters=32，kernel_size=3*3，加入padding，且使用relu
model.add(Conv2D(32, (3, 3), padding= 'same', activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))  #建立池化層，大小2*2，取最大值


#使用Flatten將維的輸入一維化，使用於卷積層到全連接層的過度
model.add(Flatten())
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立全連階層，512個輸出，且使用relu
model.add(Dense(512, activation='relu'))
#防止過度擬合，段開比例0.1
model.add(Dropout(0.1))
#建立全連階層，10個輸出，並且使用softmax
#分類問題常用softmax當output的activation function
#將output轉換到[0,1]之間且softmax output相加為1
model.add(Dense(10, activation='softmax'))
#總結輸出現在連接狀態
model.summary()

#編譯並選擇損失函數、優化方式及成效衡量方式
model.compile(loss="categorical_crossentropy",
              optimizer="adam",
              metrics=['accuracy'])



#訓練過程，儲存於train_history
#Validation_split : 驗證集的比例
#Epochs : 訓練次數
#Batch_size : 高，則快，但通常需要更多epochs
#這是因為Batch_Size大，一個 Epoch 可以跑得 Iteration 數就成比例變少，
#就沒有足夠的梯度下降讓損失函數到平穩的低點，
#所以必須加大 Epoch 數，這樣訓練時間又變長了。

#Verbose : 顯示測試結果的信息，有 (0、1、2)三種選項
#verbose = 0: 在控制檯沒有任何輸出
#verbose = 1: 顯示進度條
#verbose =2: 為每個epoch輸出一行記錄
train_history = model.fit(data_train_X,
                          data_train_Y,
                          batch_size=32,
                          epochs=128,
                          verbose=1,
                          validation_split=0.1)


#顯示損失函數，個階段訓練成果
score = model.evaluate(data_test_X, data_test_Y, verbose=2)
print('Test loss:', score[0])  #輸出Test loss
print('Test accuracy:', score[1])  #輸出Test accuracy


#輸出訓練曲線
plt.plot(train_history.history['loss'])  #輸出訓練過程中的loss
plt.plot(train_history.history['val_loss'])  #輸出訓練過程中的val_loss
plt.title('Train History')  #圖片title
plt.ylabel('loss')  #圖片ylabel
plt.xlabel('Epoch')  #圖片xlabel
plt.legend(['loss', 'val_loss'], loc='upper left')  #圖片圖例
plt.show()  #圖片輸出


# In[ ]:




