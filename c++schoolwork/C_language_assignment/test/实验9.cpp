#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    double x, y, z;
} points[10];

double matrixB[3][4]; // 修改为3x4矩阵，因为只有3个向量
double matrixB1[3][4];
double matrixB2[3][4];
double matrixB3[3][4];
double matrixC[3][2]; // 修改为3x2矩阵，因为只有3个方程

int main() {
    cout << "请输入需要计算的几何问题，我会帮你解决体积计算等问题。" << endl;
    int t = 114514;
    while(t--) {
        int op;
        cout << "请输入操作选项：";
        cin >> op;
        if(op == 1) {
            cout << "请依次输入四个点的坐标：" << endl;
            cout << "请输入第一个点的坐标：";
            cin >> points[0].x >> points[0].y >> points[0].z;
            for(int i = 1; i <= 3; i++) {
                cin >> points[i].x >> points[i].y >> points[i].z;
                matrixB[0][i] = points[i].x - points[0].x;
                matrixB[1][i] = points[i].y - points[0].y;
                matrixB[2][i] = points[i].z - points[0].z;
            }
            double v = abs(matrixB[0][1]*(matrixB[1][2]*matrixB[2][3] - matrixB[1][3]*matrixB[2][2]) -
                          matrixB[0][2]*(matrixB[1][1]*matrixB[2][3] - matrixB[1][3]*matrixB[2][1]) +
                          matrixB[0][3]*(matrixB[1][1]*matrixB[2][2] - matrixB[1][2]*matrixB[2][1]));
            cout << fixed << setprecision(4) << "体积为：" << v << endl;
        }
        else if(op == 2) {
            cout << "请依次输入四个点的坐标：" << endl;
            cout << "请输入第一个点的坐标：";
            cin >> points[0].x >> points[0].y >> points[0].z;
            for(int i = 1; i <= 3; i++) {
                cin >> points[i].x >> points[i].y >> points[i].z;
                matrixB[0][i] = points[i].x - points[0].x;
                matrixB[1][i] = points[i].y - points[0].y;
                matrixB[2][i] = points[i].z - points[0].z;
            }
            double v = abs(matrixB[0][1]*(matrixB[1][2]*matrixB[2][3] - matrixB[1][3]*matrixB[2][2]) -
                          matrixB[0][2]*(matrixB[1][1]*matrixB[2][3] - matrixB[1][3]*matrixB[2][1]) +
                          matrixB[0][3]*(matrixB[1][1]*matrixB[2][2] - matrixB[1][2]*matrixB[2][1]));
            cout << fixed << setprecision(4) << "体积为：" << v / 6 << endl;
        }
        else if(op == 3) {
            cout << "请输入四个点的坐标：" << endl;
            for(int n = 1; n <= 4; n++) {
                cin >> points[n].x >> points[n].y >> points[n].z;
            }
            matrixB[0][1] = points[2].y - points[1].y;
            matrixB[0][2] = points[1].x - points[2].x;
            matrixB[0][3] = 0;
            matrixB[1][1] = 0;
            matrixB[1][2] = points[2].z - points[1].z;
            matrixB[1][3] = points[1].y - points[2].y;
            matrixB[2][1] = points[4].z - points[3].z;
            matrixB[2][2] = 0;
            matrixB[2][3] = points[3].x - points[4].x;
            matrixC[0][1] = points[1].x * points[2].y - points[2].x * points[1].y;
            matrixC[1][1] = points[1].y * points[2].z - points[2].y * points[1].z;
            matrixC[2][1] = points[3].x * points[4].z - points[4].x * points[3].z;
            double d = abs(matrixB[0][1]*(matrixB[1][2]*matrixB[2][3] - matrixB[1][3]*matrixB[2][2]) -
                          matrixB[0][2]*(matrixB[1][1]*matrixB[2][3] - matrixB[1][3]*matrixB[2][1]) +
                          matrixB[0][3]*(matrixB[1][1]*matrixB[2][2] - matrixB[1][2]*matrixB[2][1]));
            for(int i = 0; i < 3; i++) {
                for(int j = 1; j < 4; j++) {
                    if(i == 0) {
                        matrixB1[j][i] = matrixC[j][1];
                    } else {
                        matrixB1[j][i] = matrixB[j][i];
                    }
                }
            }
            double d1 = abs(matrixB1[0][1]*(matrixB1[1][2]*matrixB1[2][3] - matrixB1[1][3]*matrixB1[2][2]) -
                           matrixB1[0][2]*(matrixB1[1][1]*matrixB1[2][3] - matrixB1[1][3]*matrixB1[2][1]) +
                           matrixB1[0][3]*(matrixB1[1][1]*matrixB1[2][2] - matrixB1[1][2]*matrixB1[2][1]));
            for(int i = 0; i < 3; i++) {
                for(int j = 1; j < 4; j++) {
                    if(i == 1) {
                        matrixB2[j][i] = matrixC[j][1];
                    } else {
                        matrixB2[j][i] = matrixB[j][i];
                    }
                }
            }
            double d2 = abs(matrixB2[0][1]*(matrixB2[1][2]*matrixB2[2][3] - matrixB2[1][3]*matrixB2[2][2]) -
                           matrixB2[0][2]*(matrixB2[1][1]*matrixB2[2][3] - matrixB2[1][3]*matrixB2[2][1]) +
                           matrixB2[0][3]*(matrixB2[1][1]*matrixB2[2][2] - matrixB2[1][2]*matrixB2[2][1]));
            for(int i = 0; i < 3; i++) {
                for(int j = 1; j < 4; j++) {
                    if(i == 2) {
                        matrixB3[j][i] = matrixC[j][1];
                    } else {
                        matrixB3[j][i] = matrixB[j][i];
                    }
                }
            }
            double d3 = abs(matrixB3[0][1]*(matrixB3[1][2]*matrixB3[2][3] - matrixB3[1][3]*matrixB3[2][2]) -
                           matrixB3[0][2]*(matrixB3[1][1]*matrixB3[2][3] - matrixB3[1][3]*matrixB3[2][1]) +
                           matrixB3[0][3]*(matrixB3[1][1]*matrixB3[2][2] - matrixB3[1][2]*matrixB3[2][1]));
            if(d1 / d != 0 && d3 / d != 0) {
                cout << "计算结果为0，无法确定交点。" << endl;
                continue;
            }
            cout << fixed << setprecision(4) << "交点坐标为：" << "(" << d1 / d << "," << d2 / d << "," << d3 / d << ")" << endl;
            points[0].x = d1 / d,