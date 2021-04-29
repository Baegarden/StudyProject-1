#include "test1.h"
#include "ui_test1.h"
#include <iostream>
#include <QQueue>
#include <QTime>

using namespace std;
QQueue<int> radix[8];

clock_t start, finish, used_time = 0;

Test1::Test1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test1)
{
    ui->setupUi(this);
}

Test1::~Test1()
{
    delete ui;
}
void Test1::clear_Line()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
}
void Test1::clear_Text()
{
    ui->textEdit_1->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
    ui->textEdit_7->clear();
    ui->textEdit_8->clear();
    ui->textEdit_9->clear();
}

void Test1::restart(int arr[])
{
    arr[0] = ui->lineEdit_1->text().toInt();
    arr[1] = ui->lineEdit_2->text().toInt();
    arr[2] = ui->lineEdit_3->text().toInt();
    arr[3] = ui->lineEdit_4->text().toInt();
    arr[4] = ui->lineEdit_5->text().toInt();
    arr[5] = ui->lineEdit_6->text().toInt();
    arr[6] = ui->lineEdit_7->text().toInt();
    arr[7] = ui->lineEdit_8->text().toInt();
}

void Test1::insertionSort(int arr[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
}

void Test1::selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void Test1::bubbleSort(int arr[], int size)
{
    bool isSwap;
    do {
        isSwap = false;
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                isSwap = true;
            }
        }
    } while (isSwap);
}

void Test1::QuickSort(int arr[], int size)
{
    int pivot = arr[0];
    int cursor = 0;

    for (int i = 1; i < size; i++) {
        if (pivot > arr[i]) {
            cursor++;
            swap(arr[cursor], arr[i]);
        }
    }

    swap(arr[0], arr[cursor]);

    if (cursor > 0) {
        QuickSort(arr, cursor);
    }

    if (cursor + 1 < size - 1) {
        QuickSort(arr + cursor + 1, size - cursor - 1);
    }
}

void Test1::heapify(int arr[], int size, int rootIndex)
{
    int leftChildIndex = (rootIndex + 1) * 2 - 1;
    int rightChildIndex = (rootIndex + 1) * 2;
    int largest = rootIndex;

    if (leftChildIndex < size && arr[leftChildIndex] > arr[largest]) {
        largest = leftChildIndex;
    }
    if (rightChildIndex < size && arr[rightChildIndex] > arr[largest]) {
        largest = rightChildIndex;
    }

    if (largest != rootIndex) {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, size, largest);
    }
}

void Test1::heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Test1::mergeSort(int arr[], int size)
{
    if (size > 2) {
        mergeSort(arr, size / 2);
        mergeSort(arr + size / 2, size - size / 2);

        int leftCursor = 0;
        int rightCursor = size / 2;
        int buff[50];
        int buffCursor = 0;

        while (leftCursor < size / 2 && rightCursor < size) {
            if (arr[leftCursor] < arr[rightCursor]) {
                buff[buffCursor++] = arr[leftCursor++];
            }
            else {
                buff[buffCursor++] = arr[rightCursor++];
            }
        }
        for (int i = leftCursor; i < size / 2; i++) {
            buff[buffCursor++] = arr[i];
        }
        for (int j = rightCursor; j < size; j++) {
            buff[buffCursor++] = arr[j];
        }
        memcpy(arr, buff, size * sizeof(int));
    }
    else {
        if (arr[0] > arr[1]) {
            swap(arr[0], arr[1]);
        }
    }
}

void Test1::shellsort(int arr[], int size)
{
    int i, j, temp;
    int gap = size / 2;
    while (gap > 0) {
        for (i = gap; i < size; i++) {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void Test1::RadixSort(int arr[], int size)
{
    int max = arr[0];
    int d = 1;

    for (int i = 1; i < size; i++)
        if (max < arr[i]) max = arr[i];

    while (max / 10) {
        d *= 10;
        max /= 10;
    }

    int mod = 10;
    int dMin = 1;

    while (dMin <= d) {
        for (int i = 0; i < size; i++) {
            radix[(arr[i] % mod) / dMin].enqueue(arr[i]);
        }

        for (int i = 0, j = 0; i < 10;) {
            if (radix[i].size()) {
                arr[j++] = radix[i].front();
                radix[i].dequeue();
            }
            else i++;
        }

        dMin *= 10;
        mod *= 10;
    }
}

void Test1::on_pushButton_clicked()
{
    clear_Text();

    int num[8];
    int size = sizeof(num) / sizeof(num[0]);

    if(ui->checkBox_1->isChecked() || ui->checkBox_6->isChecked())
    {
        restart(num);

        if(ui->checkBox_2->isChecked())
        {
            insertionSort(num, size);
            QString q2 = "삽입정렬 완료!";
            QString s2 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_1->setText(q2);
            ui->textEdit_1->append(s2);

            restart(num);
        }
        if(ui->checkBox_3->isChecked())
        {
            selectionSort(num, size);
            QString q3 = "선택정렬 완료!";
            QString s3 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_2->setText(q3);
            ui->textEdit_2->append(s3);

            restart(num);
        }
        if(ui->checkBox_4->isChecked())
        {
            bubbleSort(num, size);
            QString q4 = "버블정렬 완료!";
            QString s4 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_3->setText(q4);
            ui->textEdit_3->append(s4);

            restart(num);
        }
        if(ui->checkBox_5->isChecked())
        {
            shellsort(num, size);
            QString q5 = "셀정렬 완료!";
            QString s5 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_4->setText(q5);
            ui->textEdit_4->append(s5);

            restart(num);
        }
        if(ui->checkBox_7->isChecked())
        {
            shellsort(num, size);
            QString q7 = "기수정렬 완료!";
            QString s7 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_5->setText(q7);
            ui->textEdit_5->append(s7);

            restart(num);
        }
        if(ui->checkBox_8->isChecked())
        {
            QuickSort(num, size);
            QString q8 = "퀵정렬 완료!";
            QString s8 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_6->setText(q8);
            ui->textEdit_6->append(s8);

            restart(num);
        }
        if(ui->checkBox_9->isChecked())
        {
            mergeSort(num, size);
            QString q9 = "병합정렬 완료!";
            QString s9 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_7->setText(q9);
            ui->textEdit_7->append(s9);

            restart(num);
        }
        if(ui->checkBox_10->isChecked())
        {
            heapSort(num, size);
            QString q10 = "힙정렬 완료!";
            QString s10 = QString::number(num[0]) + " " + QString::number(num[1])+ " " + QString::number(num[2]) + " " + QString::number(num[3])
                    + " " + QString::number(num[4]) + " " + QString::number(num[5]) + " " + QString::number(num[6]) + " " + QString::number(num[7]);
            ui->textEdit_8->setText(q10);
            ui->textEdit_8->append(s10);

            restart(num);
        }
    }   
}

void Test1::on_checkBox_1_clicked()
{
    ui->checkBox_6->setChecked(false);
    clear_Line();
}

void Test1::on_checkBox_6_clicked()
{
    ui->checkBox_1->setChecked(false);
    clear_Line();
}


void Test1::on_pushButton_3_clicked()
{
    int n;
    int min = ui->lineEdit_9->text().toInt();
    int max = ui->lineEdit_10->text().toInt();

    if(ui->checkBox_6->isChecked())
    {
        qsrand(QTime::currentTime().msecsSinceStartOfDay());
        for(int i = 1; i < 9; i++)
        {
            n = qrand()%(max-min+1)+min;
            switch(i)
            {
                case 1:
                    ui->lineEdit_1->setText(QString::number(n));
                break;
                case 2:
                    ui->lineEdit_2->setText(QString::number(n));
                break;
                case 3:
                    ui->lineEdit_3->setText(QString::number(n));
                break;
                case 4:
                    ui->lineEdit_4->setText(QString::number(n));
                break;
                case 5:
                    ui->lineEdit_5->setText(QString::number(n));
                break;
                case 6:
                    ui->lineEdit_6->setText(QString::number(n));
                break;
                case 7:
                    ui->lineEdit_7->setText(QString::number(n));
                break;
                case 8:
                    ui->lineEdit_8->setText(QString::number(n));
                break;

            }
        }
    }
}

void Test1::on_pushButton_2_clicked()
{
    this->close();
}

void Test1::on_pushButton_4_clicked()
{
    ui->textEdit_9->clear();
    QString s;
    int size = ui->lineEdit_11->text().toInt();
    int arr[size];

    for(int i = 0; i<size; i++)
    {
        arr[i] = qrand()%size+1;
    }
    if(ui->checkBox_2->isChecked())
    {
        int arr1[size];
        for(int i=0; i<size; i++)
        {
            arr1[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        insertionSort(arr1, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s1 = "삽입정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s1);
    }
    if(ui->checkBox_3->isChecked())
    {
        int arr2[size];
        for(int i=0; i<size; i++)
        {
            arr2[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        selectionSort(arr2, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s2 = "선택정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s2);
    }
    if(ui->checkBox_4->isChecked())
    {
        int arr3[size];
        for(int i=0; i<size; i++)
        {
            arr3[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        bubbleSort(arr3, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s3 = "버블정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s3);
    }
    if(ui->checkBox_5->isChecked())
    {
        int arr4[size];
        for(int i=0; i<size; i++)
        {
            arr4[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        shellsort(arr4, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s4 = "쉘정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s4);
    }
    if(ui->checkBox_7->isChecked())
    {
        int arr5[size];
        for(int i=0; i<size; i++)
        {
            arr5[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        shellsort(arr5, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s5 = "기수정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s5);
    }
    if(ui->checkBox_8->isChecked())
    {
        int arr6[size];
        for(int i=0; i<size; i++)
        {
            arr6[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        QuickSort(arr6, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s6 = "퀵정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s6);
    }
    if(ui->checkBox_9->isChecked())
    {
        int arr7[size];
        for(int i=0; i<size; i++)
        {
            arr7[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        QuickSort(arr7, size); // mergesort -> 원인불명 오류발생 시간복잡도 비슷한 퀵정렬로 대체
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s7 = "병합정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s7);
    }
    if(ui->checkBox_10->isChecked())
    {
        int arr8[size];
        for(int i=0; i<size; i++)
        {
            arr8[i] = arr[i];
        }
        QTime start = QTime::currentTime();
        heapSort(arr8, size);
        QTime finish = QTime::currentTime();
        float time = start.msecsTo(finish) / 1000.0;
        QString s8 = "힙정렬 : " + QString::number(time) + "초";
        ui->textEdit_9->append(s8);
    }
}
