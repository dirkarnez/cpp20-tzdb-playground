#include <chrono>
#include <iostream>
 
int main()
{
  std::cout << "TZDB List:\n";
  std::chrono::tzdb_list& listDB = std::chrono::get_tzdb_list();
  for (auto& rDB : listDB)
    std::cout << " - " << rDB.version << "\n";
 
  std::cout << "\nDefault TZDB\n";
  const std::chrono::tzdb& db = std::chrono::get_tzdb();
  std::cout << " Version: " << db.version << ", with "
      << db.zones.size() << " zones, "
      << db.links.size() << " zone links\n";
 
  std::cout << " Links:\n";
  for (auto& link : db.links)
    std::cout << "  - " << link.name() << ":" << link.target() << "\n";
  std::cout << " Zones:\n";
  for (auto& zone : db.zones)
    std::cout << "  - " << zone.name() << "\n";
}
