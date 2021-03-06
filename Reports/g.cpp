/*





Remember when you were second year CS and you wanted to do something cool? This was what I came up with.    
The actual version that's currently used is the scheduleG.java 





*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct brand {
	int numSticks = 0;
	double dollarAmount = 0;
};

int main(int argc, char * argv[]) {
	brand marlboro, wings, camel, newport, state, dunhill, amer, maverick, trues, kent, wave, usa, sonoma, montclair, kool, misty, salem,
		winston, tareyton, pallmall, more, doral, capri, carlton, virslim, saratoga, parliament, merit, lm, bh, now, lucky, vantage, fortuna,
		basic, kamel, camelSoft, pallmallSoft, amerOrg, blackgold, hint, mcd, classic, fantasia, natCube, natKing;
	
	ifstream inFile, stickFile;
	ofstream outFile, MyExcelFile, MyDollarsFile;

	int pmtotalsticks = 0, rjrtotalsticks = 0, itgtotalsticks = 0, santafetotalsticks = 0, natshermantotalsticks = 0,
		commonwealthtotalsticks = 0, jtitotalsticks = 0, totaltotal = 0;
	double pmtotalsales = 0, rjrtotalsales = 0, itgtotalsales = 0, santafetotalsales = 0, natshermantotalsales = 0,
		commonwealthtotalsales = 0, jtitotalsales = 0, salestotaltotal = 0;

	MyExcelFile.open("C:\\Users\\USERNAME\\Desktop\\Schedule G.csv");
	MyDollarsFile.open("C:\\Users\\USERNAME\\Desktop\\Dollar Amount.csv");

	inFile.open("C:\\Users\\USERNAME\\Desktop\\purchases.txt");
	outFile.open("C:\\Users\\USERNAME\\Desktop\\sticks.txt");
	stickFile.open("C:\\Users\\USERNAME\\Desktop\\sticks.txt");

	int counter = 0, numLine = 0, sticks;
	double dollars;
	string junk, upc, brandLine, line, bits[20], dollarsString, sticksString, month;

	if (inFile.fail()) {
		cout << "Input file did not open correctly\n";
		exit(1);
	}
	if (outFile.fail()) {
		cout << "Output file did not open correctly\n";
		exit(1);
	}

	int i;  bool a;

//input file getlines don't have any unique terminators and for this to work, we need something distinct at the end of each line
//because there are a variety of stuff in the lines but the number of cartons and then the dollar amount at the end of each line
//the following while loop takes the entire input file and replicates in another file while adding '#' at the end of each line

	while (!inFile.eof()) {
		getline(inFile, line);
		outFile << line << '#' << endl;
	}

	while (!stickFile.eof() && brandLine != "Total") {
		while (counter < 48) {/***************************counter < 48 when the company name is three words eg "Moshe Trenk Inc."
		                                           increment the 48 for each additional word********************************/
			stickFile >> junk;
			counter++;
			if (counter == 4)         
				month = junk;           //the fourth item is the month
			if (counter == 9) {
				month += " - ";         //the ninth item is the year
				month += junk;          //month is now something like "April - 2046"
			}
		}
		stickFile >> upc;
		//if the length is 1, 2, or 3 then it's not an item and likely a page break so skip it
		if (upc.length() == 1 || upc.length() == 2 || upc.length() == 3) {
			getline(stickFile, junk);
			goto nextline;
		}
		
		stickFile >> brandLine;
		
		/********************************************************************
		In this if statement add any items that are sold but not defined in brands above. Otherwise the program will crash
		There can't be any risk of mistakenly adding a miscellaneous item as a cigarette so either define it as a brand 
		of cigarettes or exclude it here by adding it to the if statement
		********************************************************************/
		if (brandLine == "TUMS" || brandLine == "TRIDENT" || brandLine == "SKITTLES" || brandLine == "SCENTED" || brandLine == "ORBIT" 
		|| brandLine == "JUMBO" || brandLine == "HALLS" || brandLine == "CHIC" || brandLine == "NESTLE" || brandLine == "VUSE" 
		|| brandLine == "MarkTen" || brandLine == "BLO" || brandLine == "KODIAK" || brandLine == "SKOAL" || brandLine == "TRIVO" 
		|| brandLine == "ENTOURAGE" || brandLine == "BLACK" || brandLine == "WHITE") {
			getline(stickFile, junk);
			goto nextline;
		}
		
		//this is a horribly inefficient way to go about it, especially for
		//big data. Having said that, for this program it's not an issue
		for (i = 0, a = false; a != true; i++) {
			stickFile >> bits[i];
			for (int r = 0; r < bits[i].length() && a != true; r++) {
				if ((bits[i])[r] == '#')
					a = true;
			}
		}

		sticksString = bits[i - 2];
		dollarsString = bits[i - 1];
		dollarsString.pop_back(); // removes '#' sign 

		sticks = stoi(sticksString) * 200; //counting individual sticks
		dollars = stof(dollarsString);
		roundf(dollars * 100) / 100;

		if (brandLine == "MARL" || brandLine == "MARLBORO") {//remove marl snus?
			marlboro.dollarAmount += dollars;
			marlboro.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "WINGS") {
			wings.dollarAmount += dollars;
			wings.numSticks += sticks;
			jtitotalsales += dollars;
			jtitotalsticks += sticks;
		}
		else if (brandLine == "NEWPORT" || brandLine == "NEW") {
			newport.dollarAmount += dollars;
			newport.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "CAMEL" && upc != "10113" && upc != "34496" && upc != "34502" && upc != "34510" && upc != "34529" && upc != "34531") {
			camel.dollarAmount += dollars;
			camel.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (upc == "10113") {
			camelSoft.dollarAmount += dollars;
			camelSoft.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "555") {
			state.dollarAmount += dollars;
			state.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "DUNHILL") {
			dunhill.dollarAmount += dollars;
			dunhill.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "AMER" && upc != "85534" && upc != "85535" && upc != "10090") {//add other AS Pouches
			amer.dollarAmount += dollars;
			amer.numSticks += sticks;
			santafetotalsales += dollars;
			santafetotalsticks += sticks;
		}
		else if (upc == "85534" || upc == "85535") {
			amerOrg.dollarAmount += dollars;
			amerOrg.numSticks += sticks;
			santafetotalsales += dollars;
			santafetotalsticks += sticks;
		}
		else if (brandLine == "MAVERICK") {
			maverick.dollarAmount += dollars;
			maverick.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "TRUE") {
			trues.dollarAmount += dollars;
			trues.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "KENT") {
			kent.dollarAmount += dollars;
			kent.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "WAVE") {
			wave.dollarAmount += dollars;
			wave.numSticks += sticks;
			jtitotalsales += dollars;
			jtitotalsticks += sticks;
		}
		else if (brandLine == "USA") {
			usa.dollarAmount += dollars;
			usa.numSticks += sticks;
			commonwealthtotalsales += dollars;
			commonwealthtotalsticks += sticks;
		}
		else if (brandLine == "SONOMA") {
			sonoma.dollarAmount += dollars;
			sonoma.numSticks += sticks;
			commonwealthtotalsales += dollars;
			commonwealthtotalsticks += sticks;
		}
		else if (brandLine == "MONTCLAIR") {
			montclair.dollarAmount += dollars;
			montclair.numSticks += sticks;
			commonwealthtotalsales += dollars;
			commonwealthtotalsticks += sticks;
		}
		else if (brandLine == "KOOL") {
			kool.dollarAmount += dollars;
			kool.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "MISTY") {
			misty.dollarAmount += dollars;
			misty.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "SALEM") {
			salem.dollarAmount += dollars;
			salem.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "WINSTON") {
			winston.dollarAmount += dollars;
			winston.numSticks += sticks;
			itgtotalsales += dollars;
			itgtotalsticks += sticks;
		}
		else if (brandLine == "TAREYTON") {
			tareyton.dollarAmount += dollars;
			tareyton.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "PALL" && upc != "06518") {
			pallmall.dollarAmount += dollars;
			pallmall.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (upc == "06518") {
			pallmallSoft.dollarAmount += dollars;
			pallmallSoft.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "MORE") {
			more.dollarAmount += dollars;
			more.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "DORAL") {
			doral.dollarAmount += dollars;
			doral.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "CAPRI") {
			capri.dollarAmount += dollars;
			capri.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "CARLTON") {
			carlton.dollarAmount += dollars;
			carlton.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "VIR") {
			virslim.dollarAmount += dollars;
			virslim.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "SARATOGA") {
			saratoga.dollarAmount += dollars;
			saratoga.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "PARL" || brandLine == "PARLIAMENT") {
			parliament.dollarAmount += dollars;
			parliament.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "MERIT") {
			merit.dollarAmount += dollars;
			merit.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "L") {
			lm.dollarAmount += dollars;
			lm.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "B") {
			bh.dollarAmount += dollars;
			bh.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "NOW") {
			now.dollarAmount += dollars;
			now.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "LUCKY") {
			lucky.dollarAmount += dollars;
			lucky.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "VANTAGE") {
			vantage.dollarAmount += dollars;
			vantage.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "FORTUNA") {
			fortuna.dollarAmount += dollars;
			fortuna.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (brandLine == "BASIC") {
			basic.dollarAmount += dollars;
			basic.numSticks += sticks;
			pmtotalsales += dollars;
			pmtotalsticks += sticks;
		}
		else if (brandLine == "Kamel") {
			kamel.dollarAmount += dollars;
			kamel.numSticks += sticks;
			rjrtotalsales += dollars;
			rjrtotalsticks += sticks;
		}
		else if (upc == "50520") {
			blackgold.dollarAmount += dollars;
			blackgold.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "64120" || upc == "60120") {
			classic.dollarAmount += dollars;
			classic.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "84752") {
			fantasia.dollarAmount += dollars;
			fantasia.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "75161") {
			hint.dollarAmount += dollars;
			hint.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "77491") {
			mcd.dollarAmount += dollars;
			mcd.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "78386") {
			natCube.dollarAmount += dollars;
			natCube.numSticks += sticks / 2;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else if (upc == "20220" || upc == "22220") {
			natKing.dollarAmount += dollars;
			natKing.numSticks += sticks;
			natshermantotalsales += dollars;
			natshermantotalsticks += sticks;
		}
		else
			goto nextline;

		for (int j = 0; j < 20; j++)
			bits[j] = "";


	nextline:
		void;

	}

	//eof, rest of stuff starts here


	salestotaltotal = pmtotalsales + rjrtotalsales + itgtotalsales + commonwealthtotalsales + santafetotalsales + natshermantotalsales +
		jtitotalsales;

	MyExcelFile << "COMPANY NAME HERE" << endl;
	MyExcelFile << "FEIN: 00-0000000" << endl;
	MyExcelFile << month << endl;
	MyExcelFile << "Schedule G - Sticks Sales by Brand" << endl << endl;

	MyExcelFile << "Philip Morris:" << endl;
	MyExcelFile << "Basic: ,,," << basic.numSticks << endl;
	MyExcelFile << "Benson & Hedges: ,,," << bh.numSticks << endl;
	MyExcelFile << "L & M: ,,," << lm.numSticks << endl;
	MyExcelFile << "Marlboro: ,,," << marlboro.numSticks << endl;
	MyExcelFile << "Merit: ,,," << merit.numSticks << endl;
	MyExcelFile << "Parliament: ,,," << parliament.numSticks << endl;
	MyExcelFile << "Saratoga: ,,," << saratoga.numSticks << endl;
	MyExcelFile << "Virginia Slims: ,,," << virslim.numSticks << endl;
	MyExcelFile << "Philip Morris Total: ,,," << pmtotalsticks << endl << endl;

	MyExcelFile << "RJ Reynolds" << endl;
	MyExcelFile << "Camel Box: ,,," << camel.numSticks << endl;
	MyExcelFile << "Camel Non-Filter: ,,," << camelSoft.numSticks << endl;
	MyExcelFile << "Capri: ,,," << capri.numSticks << endl;
	MyExcelFile << "Carlton: ,,," << carlton.numSticks << endl;
	MyExcelFile << "Doral: ,,," << doral.numSticks << endl;
	MyExcelFile << "Dunhill: ,,," << dunhill.numSticks << endl;
	MyExcelFile << "Kamel Red: ,,," << kamel.numSticks << endl;
	MyExcelFile << "Kent: ,,," << kent.numSticks << endl;
	MyExcelFile << "Lucky Strike: ,,," << lucky.numSticks << endl;
	MyExcelFile << "Misty: ,,," << misty.numSticks << endl;
	MyExcelFile << "More: ,,," << more.numSticks << endl;
	MyExcelFile << "Newport: ,,," << newport.numSticks << endl;
	MyExcelFile << "Now: ,,," << now.numSticks << endl;
	MyExcelFile << "Pall Mall Box: ,,," << pallmall.numSticks << endl;
	MyExcelFile << "Pall Mall Soft: ,,," << pallmallSoft.numSticks << endl;
	MyExcelFile << "State Express 555: ,,," << state.numSticks << endl;
	MyExcelFile << "Tareyton: ,,," << tareyton.numSticks << endl;
	MyExcelFile << "True: ,,," << trues.numSticks << endl;
	MyExcelFile << "Vantage: ,,," << vantage.numSticks << endl;
	MyExcelFile << "RJ Reynolds Total: ,,," << rjrtotalsticks << endl << endl;

	MyExcelFile << "ITG" << endl;
	MyExcelFile << "Kool: ,,," << kool.numSticks << endl;
	MyExcelFile << "Maverick: ,,," << maverick.numSticks << endl;
	MyExcelFile << "Salem: ,,," << salem.numSticks << endl;
	MyExcelFile << "Winston: ,,," << winston.numSticks << endl;
	MyExcelFile << "ITG Total: ,,," << itgtotalsticks << endl << endl;

	MyExcelFile << "Commonwealth Brands: ,,," << endl;
	MyExcelFile << "Montclair: ,,," << montclair.numSticks << endl;
	MyExcelFile << "Sonoma: ,,," << sonoma.numSticks << endl;
	MyExcelFile << "USA: ,,," << usa.numSticks << endl;
	MyExcelFile << "Commonwealth Total: ,,," << commonwealthtotalsticks << endl << endl;

	MyExcelFile << "Santa Fe:" << endl;
	MyExcelFile << "American Spirit: ,,," << amer.numSticks << endl;
	MyExcelFile << "American Spirit Organic: ,,," << amerOrg.numSticks << endl;
	MyExcelFile << "Sante Fe Total: ,,," << santafetotalsticks << endl << endl;

	MyExcelFile << "Nat Sherman:" << endl;
	MyExcelFile << "Black & Gold: ,,," << blackgold.numSticks << endl;
	MyExcelFile << "Hint: ,,," << hint.numSticks << endl;
	MyExcelFile << "MCD: ,,," << mcd.numSticks << endl;
	MyExcelFile << "Classic: ,,," << classic.numSticks << endl;
	MyExcelFile << "Fantasia: ,,," << fantasia.numSticks << endl;
	MyExcelFile << "Naturals Cube: ,,," << natCube.numSticks << endl;
	MyExcelFile << "Naturals Kings: ,,," << natKing.numSticks << endl;
	MyExcelFile << "Nat Sherman Total: ,,," << natshermantotalsticks << endl << endl;

	MyExcelFile << "JTI:" << endl;
	MyExcelFile << "Wave: ,,," << wave.numSticks << endl;
	MyExcelFile << "Wings: ,,," << wings.numSticks << endl;
	MyExcelFile << "JTI Total: ,,," << jtitotalsticks << endl << endl;


	MyExcelFile << "Total Sticks: ,,," << pmtotalsticks + rjrtotalsticks + itgtotalsticks + commonwealthtotalsticks
		+ santafetotalsticks + natshermantotalsticks + jtitotalsticks << endl << endl << endl;

	//start dollars file

	MyDollarsFile << "Dollar Sales by Brand:" << endl;
	MyDollarsFile << "Philip Morris:" << endl;
	MyDollarsFile << "Basic: ,,," << basic.dollarAmount << endl;
	MyDollarsFile << "Benson & Hedges: ,,," << bh.dollarAmount << endl;
	MyDollarsFile << "L & M: ,,," << lm.dollarAmount << endl;
	MyDollarsFile << "Marlboro: ,,," << marlboro.dollarAmount << endl;
	MyDollarsFile << "Merit: ,,," << merit.dollarAmount << endl;
	MyDollarsFile << "Parliament: ,,," << parliament.dollarAmount << endl;
	MyDollarsFile << "Saratoga: ,,," << saratoga.dollarAmount << endl;
	MyDollarsFile << "Virginia Slims: ,,," << virslim.dollarAmount << endl;
	MyDollarsFile << "Philip Morris Total: ,,," << pmtotalsales << endl << endl;

	MyDollarsFile << "RJ Reynolds" << endl;
	MyDollarsFile << "Camel Box: ,,," << camel.dollarAmount << endl;
	MyDollarsFile << "Camel Non-Filter: ,,," << camelSoft.dollarAmount << endl;
	MyDollarsFile << "Capri: ,,," << capri.dollarAmount << endl;
	MyDollarsFile << "Carlton: ,,," << carlton.dollarAmount << endl;
	MyDollarsFile << "Doral: ,,," << doral.dollarAmount << endl;
	MyDollarsFile << "Dunhill: ,,," << dunhill.dollarAmount << endl;
	MyDollarsFile << "Kamel Red: ,,," << kamel.dollarAmount << endl;
	MyDollarsFile << "Kent: ,,," << kent.dollarAmount << endl;
	MyDollarsFile << "Lucky Strike: ,,," << lucky.dollarAmount << endl;
	MyDollarsFile << "Misty: ,,," << misty.dollarAmount << endl;
	MyDollarsFile << "More: ,,," << more.dollarAmount << endl;
	MyDollarsFile << "Newport: ,,," << newport.dollarAmount << endl;
	MyDollarsFile << "Now: ,,," << now.dollarAmount << endl;
	MyDollarsFile << "Pall Mall Box: ,,," << pallmall.dollarAmount << endl;
	MyDollarsFile << "Pall Mall Soft: ,,," << pallmallSoft.dollarAmount << endl;
	MyDollarsFile << "State Express 555: ,,," << state.dollarAmount << endl;
	MyDollarsFile << "Tareyton: ,,," << tareyton.dollarAmount << endl;
	MyDollarsFile << "True: ,,," << trues.dollarAmount << endl;
	MyDollarsFile << "Vantage: ,,," << vantage.dollarAmount << endl;
	MyDollarsFile << "RJ Reynolds Total: ,,," << rjrtotalsales << endl << endl;

	MyDollarsFile << "ITG" << endl;
	MyDollarsFile << "Kool: ,,," << kool.dollarAmount << endl;
	MyDollarsFile << "Maverick: ,,," << maverick.dollarAmount << endl;
	MyDollarsFile << "Salem: ,,," << salem.dollarAmount << endl;
	MyDollarsFile << "Winston: ,,," << winston.dollarAmount << endl;
	MyDollarsFile << "ITG Total: ,,," << itgtotalsales << endl << endl;

	MyDollarsFile << "Commonwealth Brands: ,,," << endl;
	MyDollarsFile << "Montclair: ,,," << montclair.dollarAmount << endl;
	MyDollarsFile << "Sonoma: ,,," << sonoma.dollarAmount << endl;
	MyDollarsFile << "USA: ,,," << usa.dollarAmount << endl;
	MyDollarsFile << "Commonwealth Total: ,,," << commonwealthtotalsales << endl;

	MyDollarsFile << "Santa Fe:" << endl;
	MyDollarsFile << "American Spirit: ,,," << amer.dollarAmount << endl;
	MyDollarsFile << "American Spirit Organic: ,,," << amerOrg.dollarAmount << endl;
	MyDollarsFile << "Sante Fe Total: ,,," << santafetotalsales << endl << endl;

	MyDollarsFile << "Nat Sherman:" << endl;
	MyDollarsFile << "Black & Gold: ,,," << blackgold.dollarAmount << endl;
	MyDollarsFile << "Hint: ,,," << hint.dollarAmount << endl;
	MyDollarsFile << "MCD: ,,," << mcd.dollarAmount << endl;
	MyDollarsFile << "Classic: ,,," << classic.dollarAmount << endl;
	MyDollarsFile << "Fantasia: ,,," << fantasia.dollarAmount << endl;
	MyDollarsFile << "Naturals Cube: ,,," << natCube.dollarAmount << endl;
	MyDollarsFile << "Naturals Kings: ,,," << natKing.dollarAmount << endl;
	MyDollarsFile << "Nat Sherman Total: ,,," << natshermantotalsales << endl << endl;

	MyDollarsFile << "JTI:" << endl;
	MyDollarsFile << "Wave: ,,," << wave.dollarAmount << endl;
	MyDollarsFile << "Wings: ,,," << wings.dollarAmount << endl;
	MyDollarsFile << "JTI Total: ,,," << jtitotalsales << endl << endl;


	MyDollarsFile << "Total Sales: ,,," << pmtotalsales + rjrtotalsales + itgtotalsales + commonwealthtotalsales
		+ santafetotalsales + natshermantotalsales + jtitotalsales << endl << endl << endl;
	
	MyExcelFile.close();
	MyDollarsFile.close();
	
	cin >> junk;

	return 0;
}
