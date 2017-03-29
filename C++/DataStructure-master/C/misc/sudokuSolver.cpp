#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool ok(vector<string> &board, int x, pair<int,int> p)
    {
        int region[9][2] = {0,0,0,3,0,6,3,0,3,3,3,6,6,0,6,3,6,6};
        int i = p.first;
        int j = p.second;
        //check row and column
        for(int k = 0; k < 9; k++)
        {
            if((board[i][k]!='.' && board[i][k] == (char)(x+'0')) || (board[k][j]!='.' && board[k][j] == (char)(x + '0')))
            return false;
        }
        //check 3*3
        int regionID = i/3*3 + j/3;
        printf("i=%d j=%d region=%d\n", i,j,regionID);
        int st_i = region[regionID][0], st_j = region[regionID][1];
        for(int k = 0; k < 3; k++)
        {
            int cur_i = st_i + k;
            for(int r = 0; r < 3; r++)
            {
                int cur_j = st_j + r;
                if(cur_i == i && cur_j == j) continue;
                if(board[cur_i][cur_j] == '.') continue;
                if(board[cur_i][cur_j] == (char)(x + '0'))
                    return false;
            }
        }
        return true;
    }
    void printBoard(vector<string>&board)
    {
    	for(int i = 0; i < 9; i++)
	    {
	        for(int j = 0; j < 9; j++)
	            printf("%c ", board[i][j]);
	        printf("\n");
	    }
	    printf("\n");
    }

    bool solve(vector<string> &board, vector<pair<int,int> > &unsolved, int entryID)
    {
        if(entryID == unsolved.size())
        {
        	cout << "here is one solution" << endl;
            return true;
        }
        //print cur board
        printBoard(board);
        for(int x = 1; x <= 9; x++)
        {
            if(ok(board, x, unsolved[entryID]))
            {
                pair<int,int> entry = unsolved[entryID];
                board[entry.first][entry.second] = (char)(x + '0');
                if(solve(board, unsolved, entryID+1))
                    return true;
                board[entry.first][entry.second] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<string > &board) {
        vector<pair<int,int> > unsolved;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == '.')
                    unsolved.push_back(make_pair(i,j));
        }
        solve(board, unsolved, 0);
    }
};

int main()
{
    vector<string>board;
    board.push_back("53..7....");
    board.push_back("6..195...");
    board.push_back(".98....6.");
    board.push_back("8...6...3");
    board.push_back("4..8.3..1");
    board.push_back("7...2...6");
    board.push_back(".6....28.");
    board.push_back("...419..5");
    board.push_back("....8..79");
    Solution sol;
    sol.solveSudoku(board);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return 0;
}
