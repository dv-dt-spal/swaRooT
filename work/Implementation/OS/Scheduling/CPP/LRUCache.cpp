//Standard Headers
#include <iostream>
#include <list>
#include <unordered_map>
#include <assert.h>
using namespace std;

//Class Declaration
class LRUCache
{
  public:

    //Constructor
    LRUCache(int capacity):cache_size(capacity){};

    //Get the value
    int get(int key);

    //Set the value in the cache
    void set(int key, int value);

  private:

    //List of data in the cache
    list<pair<int,int>> cache_data;

    //Map to store the cache data keys and the iterator to locate them
    unordered_map<int,decltype(cache_data.begin())> cache_map;

    //cache size
    int cache_size;
};

//Set data in cache
void LRUCache :: set(int key, int value)
{
  //Find the iterator for the given key
  auto it = cache_map.find(key);

  //Check if the key is present
  if(it == cache_map.end())
  {
    //Insert the data to the front of the cache_data
    cache_data.push_front(make_pair(key,value));

    //Insert the key and iterator to the Map
    cache_map.insert(make_pair(key,cache_data.begin()));

    //Check for cache overflow
    if(cache_map.size() > cache_size)
    {
        //Delete the last entry from the cache data as it is least used

        //Get the iterator of the end of the list
        auto list_end = cache_data.end();

        //Move the iterator to the last element
        list_end--;

        //Delete the entry from map
        //list_end is iterator which points to a pair whose first is key and
        //Seconde is value
        cache_map.erase(list_end->first);

        //Delete the entry from the list
        cache_data.pop_back();
    }
  }
}

//Get data from cache
int LRUCache :: get(int key)
{
  //Get the iterator of the map which has the iterator of the list or cache data
  //As the value. Key is the key used to store the value
  auto itr_data = cache_map.find(key);

  //If key is not in the map
  if(itr_data == cache_map.end()) return -1;

  //Splice the list so that the latest used data comes to the beginning
  //Put the iterator of the cache_data(itr_data->Second) in the beginning
  cache_data.splice(cache_data.begin(),cache_data,itr_data->second);

  //Return the value map iterator to list iterator(value in map) -> value(pair)
  return itr_data->second->second;
}

int main()
{

}
