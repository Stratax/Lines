#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    int i,j;
    unsigned char raster[1921][1081][3];
    int p1[2],p2[2];
    int size_x,size_y;
    float slope;
    srand(time(0));
    for(i = 0 ; i < 1000 ; i++){
        int red = rand()%255;
        int green =rand()%255;
        int blue = rand()%255;
        p1[0] = rand()%1920;
        p1[1] = rand()%1080;
        p2[0] = rand()%1920;
        p2[1] = rand()%1080;
        size_x = p2[0]-p1[0];
        size_y = p2[1]-p1[1];
        slope = (float)size_y/(float)size_x;
        //printf("(%d, %d)(%d, %d) -> \t%f \t %d/%d \n",p1[0],p1[1],p2[0],p2[1],slope,size_y,size_x);
        if(abs(size_x) > abs(size_y)){
            float delta = 0;
            if(size_x > 0){
                for(j = p1[0] ; j <= p2[0] ; j++){
                    int y = round(p1[1]+delta);
                    //printf("\t(%d, %d)\n",j,y);
                    raster[j][y][0] = red;
                    raster[j][y][1] = green;
                    raster[j][y][2] = blue;
                    delta+=slope;
                }

            }else{
                for(j = p1[0] ; j >= p2[0] ; j--){
                    int y = round(p1[1]-delta);
                    //printf("\t(%d, %d)\n",j,y);
                    raster[j][y][0] = red;
                    raster[j][y][1] = green;
                    raster[j][y][2] = blue;
                    delta+=slope;
                }
            }
        }else{
            float delta = 0;
            if(size_y > 0){
                for(j = p1[1] ; j <= p2[1] ; j++){
                    int x = round(p1[0]+delta);
                    //printf("\t(%d, %d)\n",x,j);
                    raster[x][j][0] = red;
                    raster[x][j][1] = green;
                    raster[x][j][2] = blue;
                    delta+=(1/slope);
                }
            }else{
                for(j = p1[1] ; j >= p2[1] ; j--){
                    int x = round(p1[0]-delta);
                    //printf("\t(%d, %d)\n",x,j);
                    raster[x][j][0] = red;
                    raster[x][j][1] = green;
                    raster[x][j][2] = blue;
                    delta+=(1/slope);
                }
            }
        }
    }


    //Print the PPM doc

    printf("P3\n1920 1080\n255\n");
    for(i = 0 ; i<1080 ; i++){
        for(j = 0 ; j<1920 ; j++){
            printf("%d %d %d\t",raster[j][i][0],raster[j][i][1],raster[j][i][2]);
        }
        printf("\n");
    }
    return 0;
}
