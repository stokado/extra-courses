#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	
	string type;
	is >> type;
	if (type == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	} else if (type == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
	} else if (type == "NEW_BUS") {
		q.type = QueryType::NewBus;
	} else if (type == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
	}
	switch (q.type) {
		case QueryType::NewBus:{
			is >> q.bus;
			int stop_count;
			is >> stop_count;
			q.stops.resize(stop_count);
			for (string& stop : q.stops) {
				is >> stop;
			}
			break;
		}
		case QueryType::BusesForStop:{
			is >> q.stop;
			break;
		}	
		case QueryType::StopsForBus:{
			is >> q.bus;
			break;
		}
		case QueryType::AllBuses:{
			break;
		}
	}
	return is;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.size()) {
		bool first = true;
		for (const string& bus : r.buses) {
			if (!first) {
				os << ' ';
			}
			first = false;
			os << bus;
		}
	} else {
		os << "No stop";
	}
	return os;
}

struct StopsForBusResponse {
	string cur_bus;
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.buses_to_stops.count(r.cur_bus)) {
		for (const auto& stop : r.buses_to_stops.at(r.cur_bus)) {
			os << "Stop " << stop << ": ";
			if (r.stops_to_buses.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (const string& other_bus : r.stops_to_buses.at(stop)) {
					if (r.cur_bus != other_bus) {
						os << other_bus << ' ';
					}
				}
			}
			os << endl;
		}
	} else {
		os << "No bus";
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()){
		os << "No buses";
	} else {
		for (const auto& bus_item : r.buses) {
			os << "Bus " << bus_item.first << ": ";
			for (const auto& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	return os;
}

class BusManager {
	public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse r;
		if (stops_to_buses.count(stop)) {
			for (const string& bus : stops_to_buses.at(stop)) {
				r.buses.push_back(bus);
			}
		}
		return r;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse r;
		if (buses_to_stops.count(bus)) {
			r.cur_bus = bus;
			r.buses_to_stops = buses_to_stops;
			r.stops_to_buses = stops_to_buses;
		}
		return r;
	}

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse r;
		if (!buses_to_stops.empty()) {
			r.buses = buses_to_stops;
		}
		return r;
	}
	private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};


int main()
{
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i)
	{
		cin >> q;
		switch (q.type)
		{
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
