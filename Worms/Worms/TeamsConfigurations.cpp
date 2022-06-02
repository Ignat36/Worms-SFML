#include "TeamsConfigurations.h"
#include "Singleton.h"

TeamsConfigurations::TeamsConfigurations(int n, int m)
{
	srand(time(NULL));

	TeamACount = n;
	TeamBCount = m;
	TeamANames.resize(n);
	TeamBNames.resize(m);

	std::ifstream fin; fin.open("Configurations/Names.txt");

	std::string name; 
	std::vector<std::string> names(20000); 
	int i = 0;
	while (fin >> name)
		names[i++] = name;

	for (int j = 0; j < n; j++)
		TeamANames[j] = names[ rand() % i ];
	
	for (int j = 0; j < m; j++)
		TeamBNames[j] = names[ rand() % i ];
	
	fin.close();
}
