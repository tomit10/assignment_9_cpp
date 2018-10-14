#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdint>

// Do not add any extra #includes without asking on the KEATS discussion forum

using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here
vector<pair<int,int>> moves (pair<int,int> p1){
vector<pair<int,int>> res;
 res.push_back(make_pair(p1.first+1,p1.second+2));
 res.push_back(make_pair(p1.first+2,p1.second+1));
 res.push_back(make_pair(p1.first+2,p1.second-1));
 res.push_back(make_pair(p1.first+1,p1.second-2));
 res.push_back(make_pair(p1.first-1,p1.second-2));
 res.push_back(make_pair(p1.first-2,p1.second-1));
 res.push_back(make_pair(p1.first-2,p1.second+1));
 res.push_back(make_pair(p1.first-1,p1.second+2));
return res;
}


vector<pair<int,int>> legal_moves(int dim, Path p, pair<int,int> pairPos){
	vector<pair<int,int>> original= moves(pairPos);
	vector<pair<int,int>> final;
	copy_if(original.begin(), original.end(), back_inserter(final),
	[dim,p](const pair<int,int> x) { 
		
	return (x.first>= 0 && x.second >= 0 && x.first < dim && x.second < dim && !(std::find(p.begin(), p.end(), x) != p.end()) );
	
	});
	
	return final;
}

pair<Path,bool> first_tour(int sizeB, Path secondP){
	int sizeP= secondP.size();
	int board_size=sizeB*sizeB;
	
	if(sizeP == board_size)
	{
		
	     pair<Path,bool> f (secondP,true);
	     return f;
	}
	else if(secondP.empty())
	{
			Path r;
			pair<Path,bool> y (r,false);
			return y;
	}
	else if(sizeB<5&&sizeB>1)
	{
		Path r;
		pair<Path,bool> y (r,false);
		return y;
	}
	else
	{
	   vector<pair<int,int>> test= legal_moves(sizeB,secondP,secondP.back());
			   
	   for(auto& t: test)
	   {
			secondP.push_back(t);
			auto e=first_tour(sizeB,secondP);
			if(e.second==true)
			{
				return e;
			}
		  	secondP.pop_back();
	   }
	
	   Path r;
	   pair<Path,bool> y (r,false);
	   return y;
	}
}
// Do not edit below this line

#endif
