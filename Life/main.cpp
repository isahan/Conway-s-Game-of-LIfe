//
//  main.cpp
//  Life
//
//  Created by Mohammed Isahan Khan on 2014-04-30.
//  Copyright (c) 2014 Mohammed Isahan Khan. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

using namespace std;

//Helper Functions.
void life(int test,int array[50][50],int r, int c);
void copy(int arr1[50][50], int arr2[50][50],int row, int col);
void liveordie(int array[50][50],int row, int col);
bool compare(int arr1[50][50], int arr2[50][50],int row, int col);
void print(int array[50][50],int row, int col);

int main(int argc, const char * argv[])
{

    int test=0;
    int row=0;
    int col=0;
    
    int arr[50][50];
    
    
    
    
    /*//Unit Test 1: Still Lifes - Block
    test=1;
    row =4;
    col = 4;
    for(int j = 1; j < col; j++)
    {
        for (int i = 1; i < row; i++) {arr[j][i] = 0;}
        
    }
    arr[2][2] = 1;
    arr[2][3] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    //*/
    
    /*//Unit Test 2: Still Lifes - Beehive
     test=1;
     row =5;
     col = 6;
     for(int j = 1; j < col; j++)
     {
     for (int i = 1; i < row; i++) {arr[j][i] = 0;}
     
     }
     arr[1][2] = 1;
     arr[2][1] = 1;
     arr[3][1] = 1;
     arr[2][3] = 1;
     arr[3][3] =1;
     arr[4][2] =1;
     //*/
    
     /*//Unit Test 3: Oscillator - Blinker
     test=1;
     row =5;
     col = 5;
     for(int j = 1; j < col; j++)
     {
     for (int i = 1; i < row; i++) {arr[j][i] = 0;}
     
     }
    
     arr[2][1] = 1;
     arr[2][2] = 1;
     arr[2][3] = 1;
     //*/
    
     /*//Unit Test 3: Oscillator - Toad
     test=1;
     row =6;
     col =6;
     for(int j = 1; j < col; j++)
     {
     for (int i = 1; i < row; i++) {arr[j][i] = 0;}
     
     }
    
     arr[2][2] = 1;
     arr[3][2] = 1;
     arr[4][2] = 1;
     arr[1][3] = 1;
     arr[2][3] = 1;
     arr[3][3] = 1;
    
     //*/
    
    
    
    if (test==1)
    {
        life(test,arr,row,col); // max 50x50
    }
    else {
        life(test,arr,row,col);
    }
    

    return 0;
    
    
}
void life(int test,int array[50][50],int r, int c)
{
    int gen[50][50];
	int next[50][50];
	int backup[50][50];
    int backup2[50][50];
    char neighborhood;
	char again;
    char cont;
    bool comparison;
    int loopcheck;
    int k;
    
 
    
    do
	{
        loopcheck=0;
		k=1;
        system("clear"); //clear screen
        int i = 0;
        int row, col;
        if (test==0){
            
        cout << endl << "Conway's Game of Life." << endl;
        do
        {
            cout << "Enter Number of Rows: (1-50) ";
            cin >> row;
        }
        while (row<0 && row>51);
        do
        {
            cout << "Enter Number of Coloums: (1-50) ";
            cin >> col;
        }
        while (col<0 && col>51);
        }
        else
        {
            row=r;
            col=c;
            
        }
        do
		{
            system("clear");
            //Generates the initial random state of the game board.
			
			if(loopcheck==0)
            {
                
                for(int j = 1; j < col; j++)
                {
                    for (int i = 1; i < row; i++) {
                        if (test==0){gen[j][i] = rand() % 2;}
                        else{gen[j][i] = array[j][i];}
                    }
                    
                }
                
               
                
    
               
                cout << "--------------" << endl << "Generation " << i << ":" << endl;
                cout << "--------------"  << endl << endl;
                //Initializes the arrays
                if(i == 0)
                copy(gen, next,row,col);
                copy(next, backup,row,col);
                print(next,row,col);
            
                i++;
                
            
                //Loop to check
                
                do
                {
                    cout << "Would you like to start? (y/n): ";
                    cin >> neighborhood;
                    loopcheck++;
                }while(neighborhood != 'y' && neighborhood != 'n');
                if (neighborhood  == 'n')
                {break;}

            }

            
            cout << "--------------" << endl << "Generation " << i << ":" << endl;
            cout << "--------------"  << endl << endl;
            copy(next, backup,row,col);
            if (i%2==0){
                copy(next,backup2,row,col);
            }
            print(next,row,col);
            liveordie(next,row,col);
            i++;
            
            //time to refresh.
            system("sleep .1");
            
            system("clear all");
            
            comparison = compare(next, backup,row,col);
            if(comparison == false) {system("clear");}
            if(comparison == true){break;}
            
            comparison = compare(next, backup2,row,col);
            if(comparison == false) {system("clear");}
            if(comparison == true){break;}
            
            
            
            if (i==k*1000)
            {
                k++;
                do
                {
                    cout << "Would you like to continue? (y/n): ";
                    cin >> cont;
                }while(cont != 'y' && cont != 'n');
            
                if (cont == 'n'){break;}
            }
            
            
		}while(!comparison);
        //Loop to check 
        do
        {
            cout << "Would you like to run another life simulation? (y/n): ";
            cin >> again;
        }while(again != 'y' && again != 'n');
	}while(again == 'y');

}

//Copies one array to another.
void copy(int arr1[50][50], int arr2[50][50],int row, int col)
{
    for(int j = 0; j < col; j++)
    {
		for(int i = 0; i < row; i++)
        arr2[j][i] = arr1[j][i];
	}
}

void liveordie(int array[50][50],int row, int col)
{
    
    int temp[50][50];
    copy(array, temp,row,col);
	for(int j = 1; j < col; j++)
 	{
 		for(int i = 1; i < row; i++)
		{
            //checks all 8 cells surrounding the current cell in the array.
            int count = 0;
            count =
            array[j-1][i] + array[j-1][i-1] + array[j][i-1] +
            array[j+1][i-1] + array[j+1][i] +
            array[j+1][i+1] + array[j][i+1] + array[j-1][i+1];
            //The cell dies.
            if(count < 2 || count > 3)
            temp[j][i] = 0;
            //The cell stays the same.
            if(count == 2)
            temp[j][i] = array[j][i];
            //The cell either stays alive, or is "born".
            if(count == 3)
            temp[j][i] = 1;
            
            
			
		}
 	}
    
    copy(temp, array,row,col);
}

/*void life(int array[50][50])
{
    
    int temp[50][50];
    copy(array, temp);
	for(int j = 1; j < 49; j++)
 	{
 		for(int i = 1; i < 49; i++)
		{
            //checks all 8 cells surrounding the current cell in the array.
            int count = 0;
            count = array[j-1][i] +
            array[j-1][i-1] +
            array[j][i-1] +
            array[j+1][i-1] +
            array[j+1][i] +
            array[j+1][i+1] +
            array[j][i+1] +
            array[j-1][i+1];
            //The cell dies.
            if(count < 2 || count > 3)
            temp[j][i] = 0;
            //The cell stays the same.
            if(count == 2)
            temp[j][i] = array[j][i];
            //The cell either stays alive, or is "born".
            if(count == 3)
            temp[j][i] = 1;
            
            
			
		}
 	}
    
    copy(temp, array);
}
//*/

bool compare(int arr1[50][50], int arr2[50][50], int row, int col)
{
	int count = 0;
	for(int j = 0; j < col; j++)
	{
		for(int i = 0; i < row; i++)
		{
			if(arr1[j][i]==arr2[j][i]){count++;}
		}
	}
    
	if(count == row*col){return true;}
	else{return false;}
}

//A live cell is marked by a '*', and a dead or vacant cell by a ' '.
void print(int array[50][50],int row, int col)
{
	for(int j = 1; j < col; j++)
 	{
 		for(int i = 1; i < row; i++)
		{
			if(array[j][i] == 1){cout << '*';}
			else{cout << ' ';}
		}
		cout << endl;
 	}
}

