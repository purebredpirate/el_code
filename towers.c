#include <stdio.h>
#include <stdlib.h> 

struct Point
{
int ID, x, y, fac;
};

void stdMerge(struct Point p_arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int u1 = m - l + 1; 
    int u2 =  r - m; 
  

    struct Point L[u1];
    struct Point R[u2]; 
  
   
    for (i = 0; i < u1; i++) 
        L[i] = p_arr[l + i]; 
    for (j = 0; j < u2; j++) 
        R[j] = p_arr[m + 1+ j]; 
  
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < u1 && j < u2) 
    { 
        if (L[i].x < R[j].x) 
        { 
            p_arr[k] = L[i]; 
            i++; 
        } 
        
        else if (L[i].x == R[j].x) 
        {     
             
              p_arr[k] = L[i];
              i++; 
        } 
        
        else
        { 
            p_arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < u1) 
    { 
        p_arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 
    while (j < u2) 
    { 
        p_arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void stdMergeSort(struct Point p_arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;
  
        
        stdMergeSort(p_arr, l, m); 
        stdMergeSort(p_arr, m+1, r); 
  
        stdMerge(p_arr, l, m, r);
    } 
} 

void finMerge(struct Point p_arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int u1 = m - l + 1; 
    int u2 =  r - m; 
  

    struct Point L[u1];
    struct Point R[u2]; 
  
   
    for (i = 0; i < u1; i++) 
        L[i] = p_arr[l + i]; 
    for (j = 0; j < u2; j++) 
        R[j] = p_arr[m + 1+ j]; 
  
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < u1 && j < u2) 
    { 
        if (L[i].ID <= R[j].ID) 
        { 
            p_arr[k] = L[i]; 
            i++; 
        } 
        
        else
        { 
            p_arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < u1) 
    { 
        p_arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 
    while (j < u2) 
    { 
        p_arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void finSort(struct Point p_arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;
  
        
        finSort(p_arr, l, m); 
        finSort(p_arr, m+1, r); 
  
        finMerge(p_arr, l, m, r);
    } 
} 


void mergeD(struct Point p_arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int u1 = m - l + 1; 
    int u2 =  r - m; 
  
   
    struct Point L[u1];
    struct Point R[u2]; 
  
    
    for (i = 0; i < u1; i++) 
        L[i] = p_arr[l + i]; 
    for (j = 0; j < u2; j++) 
        R[j] = p_arr[m + 1+ j]; 
  

    i = 0; 
    j = 0; 
    k = l; 
    while (i < u1 && j < u2) 
    { 
        if (L[i].y < R[j].y) 
        { 
            if(L[i].x == R[j].x) {
            L[i].fac--;
            R[j].fac--;
            }
            
            L[i].fac = L[i].fac - j;
            p_arr[k] = L[i]; 
            i++; 
        } 
        
        /*else if (L[i].y == R[j].y) 
        {     if(L[i].x == R[j].x){
              L[i].fac = L[i].fac - j;
              R[j].fac = R[j].fac - (u1 - i);
              p_arr[k] = L[i]; 
              }
              else{
              L[i].fac--;
              R[j].fac = R[j].fac - (u1 - i);
              p_arr[k] = L[i];
              }
              i++; 
        } */
        else
        { 
            //L[i].fac--;
            R[j].fac = R[j].fac - (u1 - i);
            p_arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   /* int t = (m - i);
    printf("%d \n", t);*/
    
    //R[j].fac = R[j].fac - t + 1;
    
    //int ext = 0;
    
    while (i < u1) 
    { 
    	L[i].fac = L[i].fac - j;
        //L[i].fac--;
        p_arr[k] = L[i]; 
        i++; 
        /*if (ext > 0) L[i].fac = L[i].fac - j;
        ext++;*/
        k++; 
    } 
    
    while (j < u2) 
    { 
    	
        p_arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeDec(struct Point p_arr[], int l, int r) 
{ 
    if (l < r) 
    { 

        int m = l+(r-l)/2;
  
        mergeDec(p_arr, l, m); 
        mergeDec(p_arr, m+1, r); 
  
        mergeD(p_arr, l, m, r);
    } 
} 

int main() {
  int n;
  int tempid, tempx, tempy;
  
  scanf("%d", &n);
  
 struct Point my_pnts[n];
 
 for (int h = 0; h <= n-1; h++){
 
 scanf("%d", &tempid);
 	
 my_pnts[h].ID = tempid;
 
 scanf("%d", &tempx);
 	
 my_pnts[h].x = tempx;
 
 scanf("%d", &tempy);
 	
 my_pnts[h].y = tempy; 
 
 my_pnts[h].fac = n-1;
 
 }
 
 
  stdMergeSort(my_pnts, 0, n - 1);
 
  mergeDec(my_pnts, 0, n - 1);
  
  finSort(my_pnts, 0, n - 1);
 
  for (int p = 0; p < n; p++){
     
     printf("%d ", my_pnts[p].ID);
     printf("%d\n", my_pnts[p].fac);
     
 }
  return 0;
}
