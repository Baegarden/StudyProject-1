#include "test2.h"
#include "ui_test2.h"
#include <iostream>
#include <cstdio>
#include <QQueue>
#include <QVector>
#include <QtAlgorithms>
#include <QTime>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int maps[10][10];
int kruskal_prims_maps[8][8];
int dijkstra_maps[8][8];
int edges[20][3];

int visited[10] = { 0 };

QQueue<int> q;

Test2::Test2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test2)
{
    ui->setupUi(this);
}

Test2::~Test2()
{
    delete ui;
}

void Test2::Setting()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
             maps[i][j] = 0;
        }
    }
}
void Test2::Setting2()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
             dijkstra_maps[i][j] = 0;
             kruskal_prims_maps[i][j] = INT_MAX;
        }
    }
}

void Test2::Clear_Edit()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
    ui->textEdit_8->clear();
    ui->textEdit_9->clear();
}

void Test2::DS1()
{
    if(ui->lineEdit0_0->text() != " ")
    {
         maps[1][ui->lineEdit0_0->text().toInt()] = maps[ui->lineEdit0_0->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_0->text().toInt()] = 1;
    }
    if(ui->lineEdit0_1->text() != " ")
    {
         maps[1][ui->lineEdit0_1->text().toInt()] = maps[ui->lineEdit0_1->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_1->text().toInt()] = 1;
    }
    if(ui->lineEdit0_2->text() != " ")
    {
         maps[1][ui->lineEdit0_2->text().toInt()] = maps[ui->lineEdit0_2->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_2->text().toInt()] = 1;
    }
    if(ui->lineEdit0_3->text() != " ")
    {
         maps[1][ui->lineEdit0_3->text().toInt()] = maps[ui->lineEdit0_3->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_3->text().toInt()] = 1;
    }
    if(ui->lineEdit0_4->text() != " ")
    {
         maps[1][ui->lineEdit0_4->text().toInt()] = maps[ui->lineEdit0_4->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_4->text().toInt()] = 1;
    }
    if(ui->lineEdit0_5->text() != " ")
    {
         maps[1][ui->lineEdit0_5->text().toInt()] = maps[ui->lineEdit0_5->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_5->text().toInt()] = 1;
    }
    if(ui->lineEdit0_6->text() != " ")
    {
         maps[1][ui->lineEdit0_6->text().toInt()] = maps[ui->lineEdit0_6->text().toInt()][1] = 1;
         visited[1] = visited[ui->lineEdit0_6->text().toInt()] = 1;
    }
}

void Test2::DS2()
{
    if(ui->lineEdit1_0->text() != " ")
    {
         maps[2][ui->lineEdit1_0->text().toInt()] = maps[ui->lineEdit1_0->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_0->text().toInt()] = 1;
    }
    if(ui->lineEdit1_1->text() != " ")
    {
         maps[2][ui->lineEdit1_1->text().toInt()] = maps[ui->lineEdit1_1->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_1->text().toInt()] = 1;
    }
    if(ui->lineEdit1_2->text() != " ")
    {
         maps[2][ui->lineEdit1_2->text().toInt()] = maps[ui->lineEdit1_2->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_2->text().toInt()] = 1;
    }
    if(ui->lineEdit1_3->text() != " ")
    {
         maps[2][ui->lineEdit1_3->text().toInt()] = maps[ui->lineEdit1_3->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_3->text().toInt()] = 1;
    }
    if(ui->lineEdit1_4->text() != " ")
    {
         maps[2][ui->lineEdit1_4->text().toInt()] = maps[ui->lineEdit1_4->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_4->text().toInt()] = 1;
    }
    if(ui->lineEdit1_5->text() != " ")
    {
         maps[2][ui->lineEdit1_5->text().toInt()] = maps[ui->lineEdit1_5->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_5->text().toInt()] = 1;
    }
    if(ui->lineEdit1_6->text() != " ")
    {
         maps[2][ui->lineEdit1_6->text().toInt()] = maps[ui->lineEdit1_6->text().toInt()][2] = 1;
         visited[2] = visited[ui->lineEdit1_6->text().toInt()] = 1;
    }
}

void Test2::DS3()
{
    if(ui->lineEdit2_0->text() != " ")
    {
         maps[3][ui->lineEdit2_0->text().toInt()] = maps[ui->lineEdit2_0->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_0->text().toInt()] = 1;
    }
    if(ui->lineEdit2_1->text() != " ")
    {
         maps[3][ui->lineEdit2_1->text().toInt()] = maps[ui->lineEdit2_1->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_1->text().toInt()] = 1;
    }
    if(ui->lineEdit2_2->text() != " ")
    {
         maps[3][ui->lineEdit2_2->text().toInt()] = maps[ui->lineEdit2_2->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_2->text().toInt()] = 1;
    }
    if(ui->lineEdit2_3->text() != " ")
    {
         maps[3][ui->lineEdit2_3->text().toInt()] = maps[ui->lineEdit2_3->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_3->text().toInt()] = 1;
    }
    if(ui->lineEdit2_4->text() != " ")
    {
         maps[3][ui->lineEdit2_4->text().toInt()] = maps[ui->lineEdit2_4->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_4->text().toInt()] = 1;
    }
    if(ui->lineEdit2_5->text() != " ")
    {
         maps[3][ui->lineEdit2_5->text().toInt()] = maps[ui->lineEdit2_5->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_5->text().toInt()] = 1;
    }
    if(ui->lineEdit2_6->text() != " ")
    {
         maps[3][ui->lineEdit2_6->text().toInt()] = maps[ui->lineEdit2_6->text().toInt()][3] = 1;
         visited[3] = visited[ui->lineEdit2_6->text().toInt()] = 1;
    }
}

void Test2::DS4()
{
    if(ui->lineEdit3_0->text() != " ")
    {
         maps[4][ui->lineEdit3_0->text().toInt()] = maps[ui->lineEdit3_0->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_0->text().toInt()] = 1;
    }
    if(ui->lineEdit3_1->text() != " ")
    {
         maps[4][ui->lineEdit3_1->text().toInt()] = maps[ui->lineEdit3_1->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_1->text().toInt()] = 1;
    }
    if(ui->lineEdit3_2->text() != " ")
    {
         maps[4][ui->lineEdit3_2->text().toInt()] = maps[ui->lineEdit3_2->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_2->text().toInt()] = 1;
    }
    if(ui->lineEdit3_3->text() != " ")
    {
         maps[4][ui->lineEdit3_3->text().toInt()] = maps[ui->lineEdit3_3->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_3->text().toInt()] = 1;
    }
    if(ui->lineEdit3_4->text() != " ")
    {
         maps[4][ui->lineEdit3_4->text().toInt()] = maps[ui->lineEdit3_4->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_4->text().toInt()] = 1;
    }
    if(ui->lineEdit3_5->text() != " ")
    {
         maps[4][ui->lineEdit3_5->text().toInt()] = maps[ui->lineEdit3_5->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_5->text().toInt()] = 1;
    }
    if(ui->lineEdit3_6->text() != " ")
    {
         maps[4][ui->lineEdit3_6->text().toInt()] = maps[ui->lineEdit3_6->text().toInt()][4] = 1;
         visited[4] = visited[ui->lineEdit3_6->text().toInt()] = 1;
    }
}

void Test2::DS5()
{
    if(ui->lineEdit4_0->text() != " ")
    {
         maps[5][ui->lineEdit4_0->text().toInt()] = maps[ui->lineEdit4_0->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_0->text().toInt()] = 1;
    }
    if(ui->lineEdit4_1->text() != " ")
    {
         maps[5][ui->lineEdit4_1->text().toInt()] = maps[ui->lineEdit4_1->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_1->text().toInt()] = 1;
    }
    if(ui->lineEdit4_2->text() != " ")
    {
         maps[5][ui->lineEdit4_2->text().toInt()] = maps[ui->lineEdit4_2->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_2->text().toInt()] = 1;
    }
    if(ui->lineEdit4_3->text() != " ")
    {
         maps[5][ui->lineEdit4_3->text().toInt()] = maps[ui->lineEdit4_3->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_3->text().toInt()] = 1;
    }
    if(ui->lineEdit4_4->text() != " ")
    {
         maps[5][ui->lineEdit4_4->text().toInt()] = maps[ui->lineEdit4_4->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_4->text().toInt()] = 1;
    }
    if(ui->lineEdit4_5->text() != " ")
    {
         maps[5][ui->lineEdit4_5->text().toInt()] = maps[ui->lineEdit4_5->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_5->text().toInt()] = 1;
    }
    if(ui->lineEdit4_6->text() != " ")
    {
         maps[5][ui->lineEdit4_6->text().toInt()] = maps[ui->lineEdit4_6->text().toInt()][5] = 1;
         visited[5] = visited[ui->lineEdit4_6->text().toInt()] = 1;
    }
}

void Test2::DS6()
{
    if(ui->lineEdit5_0->text() != " ")
    {
         maps[6][ui->lineEdit5_0->text().toInt()] = maps[ui->lineEdit5_0->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_0->text().toInt()] = 1;
    }
    if(ui->lineEdit5_1->text() != " ")
    {
         maps[6][ui->lineEdit5_1->text().toInt()] = maps[ui->lineEdit5_1->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_1->text().toInt()] = 1;
    }
    if(ui->lineEdit5_2->text() != " ")
    {
         maps[6][ui->lineEdit5_2->text().toInt()] = maps[ui->lineEdit5_2->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_2->text().toInt()] = 1;
    }
    if(ui->lineEdit5_3->text() != " ")
    {
         maps[6][ui->lineEdit5_3->text().toInt()] = maps[ui->lineEdit5_3->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_3->text().toInt()] = 1;
    }
    if(ui->lineEdit5_4->text() != " ")
    {
         maps[6][ui->lineEdit5_4->text().toInt()] = maps[ui->lineEdit5_4->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_4->text().toInt()] = 1;
    }
    if(ui->lineEdit5_5->text() != " ")
    {
         maps[6][ui->lineEdit5_5->text().toInt()] = maps[ui->lineEdit5_5->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_5->text().toInt()] = 1;
    }
    if(ui->lineEdit5_6->text() != " ")
    {
         maps[6][ui->lineEdit5_6->text().toInt()] = maps[ui->lineEdit5_6->text().toInt()][6] = 1;
         visited[6] = visited[ui->lineEdit5_6->text().toInt()] = 1;
    }
}

void Test2::DS7()
{
    if(ui->lineEdit6_0->text() != " ")
    {
         maps[7][ui->lineEdit6_0->text().toInt()] = maps[ui->lineEdit6_0->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_0->text().toInt()] = 1;
    }
    if(ui->lineEdit6_1->text() != " ")
    {
         maps[7][ui->lineEdit6_1->text().toInt()] = maps[ui->lineEdit6_1->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_1->text().toInt()] = 1;
    }
    if(ui->lineEdit6_2->text() != " ")
    {
         maps[7][ui->lineEdit6_2->text().toInt()] = maps[ui->lineEdit6_2->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_2->text().toInt()] = 1;
    }
    if(ui->lineEdit6_3->text() != " ")
    {
         maps[7][ui->lineEdit6_3->text().toInt()] = maps[ui->lineEdit6_3->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_3->text().toInt()] = 1;
    }
    if(ui->lineEdit6_4->text() != " ")
    {
         maps[7][ui->lineEdit6_4->text().toInt()] = maps[ui->lineEdit6_4->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_4->text().toInt()] = 1;
    }
    if(ui->lineEdit6_5->text() != " ")
    {
         maps[7][ui->lineEdit6_5->text().toInt()] = maps[ui->lineEdit6_5->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_5->text().toInt()] = 1;
    }
    if(ui->lineEdit6_6->text() != " ")
    {
         maps[7][ui->lineEdit6_6->text().toInt()] = maps[ui->lineEdit6_6->text().toInt()][7] = 1;
         visited[7] = visited[ui->lineEdit6_6->text().toInt()] = 1;
    }
}

void Test2::DS8()
{
    if(ui->lineEdit7_0->text() != " ")
    {
         maps[8][ui->lineEdit7_0->text().toInt()] = maps[ui->lineEdit7_0->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_0->text().toInt()] = 1;
    }
    if(ui->lineEdit7_1->text() != " ")
    {
         maps[8][ui->lineEdit7_1->text().toInt()] = maps[ui->lineEdit7_1->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_1->text().toInt()] = 1;
    }
    if(ui->lineEdit7_2->text() != " ")
    {
         maps[8][ui->lineEdit7_2->text().toInt()] = maps[ui->lineEdit7_2->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_2->text().toInt()] = 1;
    }
    if(ui->lineEdit7_3->text() != " ")
    {
         maps[8][ui->lineEdit7_3->text().toInt()] = maps[ui->lineEdit7_3->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_3->text().toInt()] = 1;
    }
    if(ui->lineEdit7_4->text() != " ")
    {
         maps[8][ui->lineEdit7_4->text().toInt()] = maps[ui->lineEdit7_4->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_4->text().toInt()] = 1;
    }
    if(ui->lineEdit7_5->text() != " ")
    {
         maps[8][ui->lineEdit7_5->text().toInt()] = maps[ui->lineEdit7_5->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_5->text().toInt()] = 1;
    }
    if(ui->lineEdit7_6->text() != " ")
    {
         maps[8][ui->lineEdit7_6->text().toInt()] = maps[ui->lineEdit7_6->text().toInt()][8] = 1;
         visited[8] = visited[ui->lineEdit7_6->text().toInt()] = 1;
    }
}

void Test2::DFS(int v)
{
    if(v != 0)
        ui->textEdit_3->append("->" + QString::number(v));

    visited[v] = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (maps[v][i] && visited[i])
            DFS(i);
    }
}

void Test2::BFS(int v)
{
    int n = 1;
    ui->textEdit_4->append("->" + QString::number(v));
    q.enqueue(v);
    while(!q.empty())
    {
        int node = q.head();
        q.dequeue();
        for(int i=1; i<9; i++)
        {
            if(maps[node][i]==1 && visited[i]==0)
            {
                visited[node]=1;
                if(n < 8)
                {
                    ui->textEdit_4->append("->" + QString::number(i));
                    n++;
                }
                q.enqueue(i);
            }
        }
    }
}

int par[8];
int v1 = 8;
int e, k;

int Test2::find(int i)
{
    while (par[i] != i)
        i = par[i];
    return i;
}

void Test2::union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

void Test2::kruskalMST(int cost[][8])
{
    int mincost = 0;

    for (int i = 0; i < 8; i++)
        par[i] = i;

    int edge_count = 0;
    while (edge_count < 8 - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        edge_count++;
        ui->textEdit_5->append("Edge " + QString::number(edge_count) + ": ("
        + QString::number(a+1) + ", " + QString::number(b+1) + ")   cost: " + QString::number(min));
        mincost += min;
    }
    ui->textEdit_5->append("Minimum cost = " + QString::number(mincost));
}

bool Test2::isValidEdge(int u, int v, QVector<bool> inMST)
{
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void Test2::primMST(int cost[][8])
{
    QVector<bool> inMST(8, false);

    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    while (edge_count < 8 - 1) {

        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            edge_count++;
            ui->textEdit_6->append("Edge " + QString::number(edge_count) + ": ("
            + QString::number(a+1) + ", " + QString::number(b+1) + ")   cost: " + QString::number(min));
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    ui->textEdit_6->append("Minimum cost = " + QString::number(mincost));
}

int Test2::minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < 8; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Test2::printSolution(int dist[])
{
    for (int i = 0; i < 8; i++)
    {
        ui->textEdit_8->append("1->" + QString::number(i+1) + "            " + QString::number(dist[i]));
    }
}


void Test2::dijkstra(int graph[8][8], int src)
{
    int dist[8];

    bool sptSet[8];

    for (int i = 0; i < 8; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < 8-1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < 8; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }

    }
    printSolution(dist);
}


struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;

    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void Test2::printArr(int dist[], int n)
{
    for (int i = 0; i < n; ++i)
        ui->textEdit_9->append("1->" + QString::number(i + 1) + "            " + QString::number(dist[i]));
}


void Test2::BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[8];


    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }


    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            return;
        }
    }

    printArr(dist, V);

    return;
}

void Test2::on_pushButton_clicked()
{

    Clear_Edit();
    Setting();
    Setting2();

    DS1(), DS2(), DS3(), DS4(), DS5(), DS6(), DS7(), DS8();

    qsrand(QTime::currentTime().msecsSinceStartOfDay()); //시드를 주어 매번 랜덤한 값으로 나타냄
    int m, p = 0;

    for(int i=1; i<9; i++) // 엣지의 개수
    {
        for(int j=0; i+j<9; j++)
        {
            if(maps[i][i+j] == 1)
            {
                if(ui->checkBox_7->isChecked())
                    m = qrand()%21-10;
                else
                    m = qrand()%20+1;
                edges[p][0] = i;
                edges[p][1] = i+j;
                edges[p][2] = m;
                kruskal_prims_maps[i-1][i+j-1] = m;
                kruskal_prims_maps[i+j-1][i-1] = m;
                dijkstra_maps[i-1][i+j-1] = m;
                dijkstra_maps[i+j-1][i-1] = m;
                p++;
                e++;
            }
        }
    }

    for(int i=0; i<8; i++) // 인접행렬로 그래프표현
    {
        QString s;
        for(int j=0; j<8; j++)
        {
             s += QString::number(dijkstra_maps[i][j]) + " ";
        }
        ui->textEdit->append(s);
    }

    for(int i=0; i<21; i++)
    {
        if(edges[i][0] == 0)
            break;
        ui->textEdit_2->append("<" + QString::number(edges[i][0]) + "    " + QString::number(edges[i][1])+ "    " +QString::number(edges[i][2]) + ">");
    }

    if(ui->checkBox->isChecked()) // BFS/DFS
    {
        DFS(1);
        BFS(1);
    }
    if(ui->checkBox_2->isChecked()) // kruskal
    {
        kruskalMST(kruskal_prims_maps);
    }
    if(ui->checkBox_3->isChecked()) // Prim
    {
        primMST(kruskal_prims_maps);
    }
    if(ui->checkBox_6->isChecked()) // dijkstra
    {
        ui->textEdit_8->append("Vertex  Distance from Source");
        dijkstra(dijkstra_maps, 0);       
    }
    if(ui->checkBox_7->isChecked()) // BellmanFord
    {
       struct Graph* graph = createGraph(8, e);


       ui->textEdit_9->append("Vertex  Distance from Source");
       for (int i = 0; i < e; i++)
       {
           graph->edge[i].src = edges[i][0] - 1;
           graph->edge[i].dest = edges[i][1] - 1;
           graph->edge[i].weight = edges[i][2];
       }

       BellmanFord(graph, 0);
    }
}

void Test2::on_checkBox_7_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_6->setChecked(false);

}

void Test2::on_checkBox_2_clicked()
{
    ui->checkBox_7->setChecked(false);
}

void Test2::on_checkBox_6_clicked()
{
    ui->checkBox_7->setChecked(false);
}
