//
//  Tracks.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Tracks.hpp"
#include "Recording.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "genericClass.hpp"
#include "Track.hpp"

using namespace std;

Tracks::Tracks(){
    
}

void Tracks::setTrackCollection(Recording *recording){
    //tracks_collection.push_back(recording);
}

Tracks::~Tracks(){
//    for (int i=0; i<tracks_collection.size();i++){
//        delete[] tracks_collection[i];
//    }

    for (auto *ptr: tracks_collection){
        delete ptr;
    }
    tracks_collection.clear();
}

void Tracks::getData(string &input){
    
    
    string values;
    size_t pos;
    vector<int> vect;
    int i, track_id, albumID, songID, track_number;
    
    pos = input.find("-t")+2;
    values = input.substr(pos);
    
    stringstream ss(values);
    
    while (ss >> i)
    {
        vect.push_back(i);
        
        if (ss.peek() == ' '){
            
            ss.ignore();
        }
        
    }
    
    if (vect.size()!=4){
        genericClass::printError();
        return;
    }
   
    track_id = vect.at(0);
    albumID = vect.at(1);
    songID = vect.at(2);
    track_number = vect.at(3);
    
    Track *track = new Track(track_id, albumID, songID, track_number);
    tracks_collection.push_back(track);
    
    cout <<*this<<endl;

}

//getter
Track *Tracks::getTrackInstance(int index){
    return tracks_collection[index];  //dereference the pointer=track instance
}

void Tracks::tracksToRespectiveAlbum(Recordings *recordings){
    
    if (tracks_collection.size()>0){
    
        for (int i=0; i<tracks_collection.size(); i++){
            for (int j=0; j<tracks_collection.size(); j++){
                
                if ( recordings->getRecordingAlbumID(i) == tracks_collection[j]->getAlbumID() ){
                    
                    
                    getTrackInstance(j)->setRecordingPtr(recordings->getRecordingInstance(i));
                    
                    
                    
                    cout <<getTrackInstance(j)->getRecordingPointer()<<endl;
                    
                }
            }
        }
    }
    
}

void Tracks::printOn(ostream &o)const{
    cout<<"TRACKS: "<<endl;
    
    for (int i=0; i<tracks_collection.size(); i++){
        //o <<(*tracks_collection[i]).toString()<<endl;
        o<<tracks_collection[i]->toString()<<endl;
    }
}


ostream & operator<<(ostream & out, const Tracks & tracks){
    tracks.printOn(out);
    
    return out;
}
