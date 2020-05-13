#include "Telefon.h"
#include "SerializerSerie.h"
#include "SerializerUser.h"
#include "RepoTemplate.h"
#include "Service.h"
#include "UI.h"
#include "Teste.h"
#include "RepoFileCSV.h"
#include "RepoFileHTML.h"

using namespace std;

int main()
{
	///*testTelefon();
	//testDrona();*/
	//testRepoTemplate();
	///*testRepoFileCSV();
	//testRepoFileHTML();
	//testService();*/
	//cout << endl;
	
	SerializerSerie* serSerie = new SerializerSerie();
	SerializerUser* serUser = new SerializerUser();
	
	RepoFileHTML<Serie*>repo("Serii.html", serSerie);
	//RepoFileCSV<Serie*>repo("Serii.csv", serSerie);
	RepoFile<User*> repoUser("Useri.txt", ' ', serUser);
	Service serv(repo, repoUser);
	UI ui(serv);
	ui.run();
}