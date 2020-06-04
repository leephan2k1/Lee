#include <stdio.h>
#include <math.h>
#include <stdlib.h>   
struct Point{
  double X;
  double Y;
};
struct Rect{
    struct Point upper_right;
    struct Point lower_left;
};
int isIn(struct Point M, struct Rect r ){
	// M.X - Upper_Right.X /  Lower_Left.X - Upper_Right.X 
    double KT_Hoanh = ((double)(M.X - r.upper_right.X))/((double)(r.lower_left.X - r.upper_right.X));
    if (KT_Hoanh < 0 || KT_Hoanh > 1) return 0;
    // M.Y - Upper_Right.Y /  Lower_Left.Y - Upper_Right.Y 
    double KT_Tung = ((double)(M.Y - r.upper_right.Y))/((double)(r.lower_left.Y - r.upper_right.Y));
    if (KT_Tung < 0 || KT_Tung > 1) return 0; 
    return 1;
}
int main(){
struct Rect r = {{2,2},{10,8}};
struct Point M={8,6};
	
if (isIn(M,r))
	printf("YES");
else printf("NO");
    return 0;
}
