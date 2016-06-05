/*
A student signed up for n workshops and wants to attend the maximum number of workshops where no two workshops overlap.
*/
#include<bits/stdc++.h>

using namespace std;

/*
Define the structs Workshops and Available_Workshops.
struct Workshop having the following members:
    The workshop's start time.
    The workshop's duration.
    The workshop's end time.
*/
struct Workshops {
    unsigned int start_time, duration, end_time;
};


/*
struct Available_Workshops having the following members:
    An integer, n (the number of workshops the student signed up for).
    An array of type Workshop array having size n.
*/
struct Available_Workshops {
    unsigned int n=0;
    Workshops* array;
    //vector<Workshops> * array;
};


/*
Creates an Available_Workshops object and initializes its elements using the elements in the start_time[] and duration[] parameters (both are of size nn). Here, start_time[i] and duration[i] are the respective start time and duration for the i-th workshop. This function must return a pointer to an Available_Workshops object.
*/
Available_Workshops* initialize (int start_time[], int duration[], int& n){
    Available_Workshops* available = new Available_Workshops();
    available->n = n;
    available->array = new Workshops[n];
    for(unsigned i=0; i<n; ++i){
        available->array[i].start_time =  start_time[i];
        available->array[i].duration =  duration[i];
        available->array[i].end_time =  start_time[i] + duration[i];
    }
    return available;
}


/*
Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.
*/
int CalculateMaxWorkshops(Available_Workshops* ptr){
    int last_success_end, count = 0;
    if(ptr->n > 0){
        count = 1;
        //sort array of Workshops according to end_time to calculate max attended
        sort(ptr->array, ptr->array + (ptr->n), 
             [&]( Workshops &a, Workshops &b){
                 return a.end_time < b.end_time;
             }
        );
        /*
        //print
        for(unsigned i=0; i<ptr->n; ++i){
            cout << ptr->array[i].start_time << ' ';
            cout << ptr->array[i].duration << ' ';
            cout << ptr->array[i].end_time << endl;
        }
        */
        last_success_end = 0;
        //check current start_time with previous end_time and store last accepted workshop
        for(unsigned i=1; i<ptr->n; ++i){
                if ( (ptr->array[i].start_time >= ptr->array[i-1].end_time)
                    || ( ptr->array[i].start_time >= ptr->array[last_success_end].end_time) ){
                    ++count;
                    last_success_end = i;
                }
        }
        /*
        //needs <algorithm> header
        return count_if(ptr->array, ptr->array + (ptr->n),
             []( Workshops &a, Workshops &b){
                 return a.end_time < b.start_time;
             }
        );
        */
    }
    delete[] ptr->array;
    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
