#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAx_INT_MAX 20
struct delicttree{
    delicttree *ltreepoint[MAx_INT_MAX]= {NULL};
    int num[2];
    
};
class Prim_tree{
    public:
        int **judge;
        int n=100;
        delicttree *root=new delicttree;
        delicttree *now=root;
        int *biaoji;
        int **src;
    public:
        Prim_tree(int size=100):n(size){
            judge = new int*[n+1];
            biaoji = new int[n+1]();
            for (int i = 0; i < n; i++) {
                judge[i] = new int[n+1]();
            }
        }
        ~Prim_tree(){
            for (int i = 0; i < n; i++) {
                delete[] judge[i];
            }
            delete[] judge;
            delete[] biaoji;
        }   
        void inittree(){
            src = new int*[n];
            for (int i = 0; i < n; i++) {
                src[i] = new int[n+1]();
            }
            while(1){
                int a, b, c;
                cout<<"请输入边的两个顶点和权重(输入0 0 0结束): ";
                cin >> a >> b >> c;
                if (a == 0 && b == 0) {
                    break;
                }

                judge[a][b] = c;
                judge[b][a] = c;
                src[a][b] = c;
                src[b][a] = c;
            }

        }
        bool checkpoint(int j){
            return !biaoji[j]; // 检查顶点j是否未被访问
        }
        // 选择顶点d的未访问邻接顶点中权值最小的顶点
        int selectpoint(int d){
            int min=0;
            for (int i=1;i<=n; i++){
                if(min==0&&checkpoint(i)){
                    min=i;
                }
                else if(src[d][i]<src[d][min]&&checkpoint(i)){
                    min=i;
                }
            
            }
            return min;
        }
        // 选择顶点d的未访问邻接顶点中权值最小的顶点的父顶点
        delicttree* selctpoint(int d, delicttree *de){
            delicttree *newtree=de;
            if(newtree->num[0]==d){
                return newtree;
            }
            else{
                for (int i=0;de->ltreepoint[i]!=NULL;i++){
                    selctpoint(d,de->ltreepoint[i]);
                }
                return NULL;
            }
        }
        bool Prim(int d){
            int min=selectpoint(d);
            if(min!=0){
                delicttree *newtree=now;
                newtree->num[0]=min;
                newtree->num[1]=src[d][min];
                cout<<"添加边: 顶点"<<d<<" -> 顶点"<<min<<" , 权重 = "<<src[d][min]<<endl;
                now=new delicttree;
                for(int i=0;i<=n;i++){
                    if(newtree->ltreepoint[i]==NULL){
                        newtree->ltreepoint[i]=now;
                        break;
                    }
                }
                biaoji[min]=1;
                if(!Prim(min)){
                    int min=0;
                    int de=0;
                    for(int i=0;checkpoint(i);i++){
                        min=selectpoint(i);
                        if(min!=0){
                            de=i;
                        }
                    }
                    if(min!=0&&de!=0){
                        delicttree *parent=selctpoint(de,root);
                        delicttree *dparent=new delicttree;
                        cout << "添加边: " << de << " - " << min << " 权重: " << src[de][min] << endl;
                        for(int i=0;parent->ltreepoint[i]!=NULL;i++){
                            if(parent->ltreepoint[i]==NULL)
                                parent->ltreepoint[i]=dparent;

                        }
                        dparent->num[0]=min;
                        dparent->num[1]=src[de][min];
                        biaoji[min]=1;
                    }
                }
                return true;
            }
            else {
                delete now;
                return false;
            }

        };
};
int main(){
    Prim_tree prim(10);
    prim.inittree();
    prim.Prim(1);
    return 0;
}
