#include <bits/stdc++.h>
using namespace std;

class Point{
public:
    int x,y;

    Point(){}
    Point(int x1, int y1){
        x=x1;
        y=y1;
    }
};

class ClosestPair{
public:
    double dist(Point p1, Point p2){
        return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    }
    double bruteForce(vector<Point> &P,int l,int r){
        double mn=DBL_MAX;
        for (int i=l;i<=r;i++){
            for (int j=i+1;j<=r;j++){
                mn=min(mn,dist(P[i],P[j]));
            }
        }
        return mn;
    }

    double stripClosest(vector<Point> &strip,double d){
        double mn=d;

        sort(strip.begin(),strip.end(),
             [](Point a,Point b){
                 return a.y<b.y;
             });

        for (int i=0;i<strip.size();i++){
            for (int j=i+1;j<strip.size() && (strip[j].y-strip[i].y)<mn;j++){
                mn=min(mn,dist(strip[i],strip[j]));
            }
        }
        return mn;
    }

    double closestUtil(vector<Point> &P,int l,int r){
        if (r-l<=2)
            return bruteForce(P,l,r);
        int mid=(l+r)/2;
        int midx=P[mid].x;
        double dl=closestUtil(P,l,mid);
        double dr=closestUtil(P,mid+1,r);

        double d=min(dl,dr);

        vector<Point> strip;
        for (int i=l;i<=r;i++){
            if (abs(P[i].x-midx)<d)
                strip.push_back(P[i]);
        }
        return min(d,stripClosest(strip,d));
    }
};

int main() {
    vector<Point> points={
        Point(9,3), Point(2,6), Point(15,3), Point(5,1),
        Point(1,2), Point(12,4), Point(7,2), Point(4,7),
        Point(16,5), Point(3,3), Point(10,5), Point(6,4),
        Point(14,6), Point(8,6), Point(11,1), Point(13,2)
    };

    sort(points.begin(),points.end(),[](Point a,Point b){
             return a.x < b.x;
         });
    ClosestPair cp;
    cout<<"Minimum distance = "<<cp.closestUtil(points,0,points.size()-1)<<endl;
    return 0;
}
