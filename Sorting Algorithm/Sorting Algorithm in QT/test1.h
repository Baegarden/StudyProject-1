#ifndef TEST1_H
#define TEST1_H

#include <QMainWindow>

namespace Ui {
class Test1;
}

class Test1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test1(QWidget *parent = 0);
    ~Test1();

public slots:
    void clear_Text();
    void clear_Line();
    void restart(int arr[]);
    void insertionSort(int arr[], int size);
    void bubbleSort(int arr[], int size);
    void selectionSort(int arr[], int size);
    void QuickSort(int arr[], int size);
    void heapify(int arr[], int size, int rootIndex);
    void heapSort(int arr[], int size);
    void mergeSort(int arr[], int size);
    void shellsort(int a[], int size);
    void RadixSort(int arr[], int size);
    void on_pushButton_clicked();

private slots:
    void on_checkBox_1_clicked();

    void on_checkBox_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Test1 *ui;    
};

#endif // TEST1_H
