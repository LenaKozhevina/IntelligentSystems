//
//  main.cpp
//  recognition
//
//  Created by Evgeny on 9/19/13.
//  Copyright (c) 2013 Evgeny. All rights reserved.
//
 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <cstdlib>
 
#define n 10
 
#pragma pack(push, 1)
struct BITMAPFILEHEADER
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
};
#pragma pack(pop)
 
 /*bool image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; */
 
/*bool image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; */
 
/*uint8_t image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; */
 
uint8_t image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
 
/*bool image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; */
/*
bool image[n][n] = {    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; */
 
 
using namespace std;
 
bool IsVertex(const int i, const int j)
{
     if (image[i][j] == 0) return false;
   
    //x x
    // y
    if (j != 0 && j != (n-1) && i != 0)
    {
        if (image[j-1][i-1] && image[j+1][i-1] && !image[i][j-1] && !image[i][j+1])
        {
            return true;
        }
    }
   
    //x
    // y
    //x
    if (j != 0 && i != 0 && i < (n-1))
    {
        if (image[i-1][j-1] && image[i+1][j-1] && !image[i-1][j] && !image[i+1][j])
        {
            return true;
        }
    }
   
    // y
    //x x
    if (i < (n-1) && j != 0 && j < (n-1))
    {
        if (image[i+1][j-1] && image[i+1][j+1] && !image[i][j-1] && !image[i][j+1])
        {
            return true;
        }
    }
   
    // x
    //y
    // x
    if (i != 0 && i < (n-1) && j < (n-1))
    {
        if (image[i-1][j+1] && image[i+1][j+1] && !image[i-1][j] && !image[i-1][j])
        {
            return true;
        }
    }
   
    //x
    //y x
    if (i != 0 && j < (n-1))
    {
        if (image[i-1][j] && image[i][j+1] && !image[i][j-1])
        {
            return true;
        }
    }
   
    //  x
    //x y
    if (i != 0 && j != 0)
    {
        if (image[i][j-1] && image[i-1][j] && !image[i][j+1])
        {
            return true;
        }
    }
   
    //x y
    //  x
    if (i < (n-1) && j != 0)
    {
        if (image[i][j-1] && image[i+1][j])
        {
            return true;
        }
    }
   
    //y x
    //x
    if (i < (n-1) && j < (n-1))
    {
        if (image[i][j+1] && image[i+1][j])
        {
            return true;
        }
    }
   
    //  x
    //y x
    if (i != 0 && j < (n-1))
    {
        if (image[i-1][j+1] && image[i][j+1] && !image[i][j-1])
        {
            return true;
        }
    }
   
    //x
    //x y
    if (i != 0 && j !=0)
    {
        if (image[i-1][j-1] && image[i][j-1] && !image[i][j+1])
        {
            return true;
        }
    }
   
    int v = 0;
    if (i != 0 && j != 0)
    {
        if (image[i-1][j-1]) v++;
    }
    if (i != 0)
    {
        if (image[i-1][j]) v++;
    }
    if (i != 0 && j < (n-1))
    {
        if (image[i-1][j+1]) v++;
    }
    if (j != 0)
    {
        if (image[i][j-1]) v++;
    }
    if (j < (n-1))
    {
        if (image[i][j+1]) v++;
    }
    if (i < (n-1) && j != 0)
    {
        if (image[i+1][j-1]) v++;
    }
    if (i < (n-1))
    {
        if (image[i+1][j]) v++;
    }
    if (i < (n-1) && j < (n-1))
    {
        if (image[i+1][j+1]) v++;
    }
   
    if (v == 1) return true;
   
    return false;
}
 
int main(int argc, const char * argv[])
{
   
    BITMAPFILEHEADER header;
    FILE* file;
    fopen_s(&file, "image5.bmp", "rb");
    if (!file)
    {
        assert(0 && "Bad");
    }
   
    fread(&header, sizeof(BITMAPFILEHEADER), 1, file);
    uint32_t offset = header.offset;
    uint8_t v;
    uint16_t temp;
    fseek(file, offset, SEEK_SET);
    for(int i = 0; i < 10; i++)
	{
        for (int j = 0; j < 10; j++)
        {
            //fread(&image[i][j], 1, 1, file);
            fread(&v, 1, 1, file);
			if (v == 0) image[i][j] = 1;
            else image[i][j] = 0;
            fread(&temp, 2, 1, file);
        }
		fread(&temp, 2, 1, file);
	}
    //ifstream bitmap("image.bmp", ios::in|ios::binary|ios::ate);
    //char* buffer;
    //bitmap.read(&header, sizeof(BITMAPFILEHEADER));
   
    //uint32_t size = header.offset;
    //bitmap.
   
	int verts = 0;
   
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (IsVertex(i, j))
                verts++;
        }
    }

    if (verts == 0)
    {
        int minI,minJ, maxI, maxJ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (image[i][j])
                {
                    minI = i;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (image[i][j])
                {
                    minJ = j;
                }
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = n-1; j >= 0; j--)
            {
                if (image[i][j])
                {
                    maxJ = j;
                }
            }
        }
        for (int j = n-1; j >= 0; j--)
        {
            for (int i = n-1; i >= 0; i--)
            {
                if (image[i][j])
                {
                    maxI = i;
                }
            }
        }
        if ((maxI-minI) != (maxJ-minJ))
            cout << "Ellipse" << endl;
        else
            cout << "Circle" << endl;
    }
    else if (verts == 1)
        cout << "Line" << endl;
    else if (verts == 2)
        cout << "Line" << endl;
    else if (verts == 3)
        cout << "Triangle" << endl;
    else if (verts == 4)
		cout << "Square" << endl;

	system("pause");
}