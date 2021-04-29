#ifndef TEST2_H
#define TEST2_H

#include <QMainWindow>

namespace Ui {
class Test2;
}

class Test2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test2(QWidget *parent = 0);
    ~Test2();

private slots:
    void on_pushButton_clicked();
    void DFS(int v);
    void BFS(int v);
    void Setting();
    void Setting2();
    void Clear_Edit();
    void DS1();
    void DS2();
    void DS3();
    void DS4();
    void DS5();
    void DS6();
    void DS7();
    void DS8();
    int find(int i);
    void union1(int i, int j);
    void kruskalMST(int cost[][8]);
    bool isValidEdge(int u, int v, QVector<bool> inMST);
    void primMST(int cost[][8]);
    int minDistance(int dist[], bool sptSet[]);
    void printSolution(int dist[]);
    void dijkstra(int graphs[8][8], int src);
    void printArr(int dist[], int n);
    void BellmanFord(struct Graph* graph, int src);

    void on_checkBox_7_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_6_clicked();

private:
    Ui::Test2 *ui;
};

#endif // TEST2_H
