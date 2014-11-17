//Alec Bayliff
 
//Includes
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
 
//Checks the number and correctness of the arguments passed to the program
void checkArgs(int argCnt, char *argVals[]);
//Checks if the Program List exists and can be read
bool checkPrgList(string prgListFile);
//Checks if the Program Trace exists and can be read
bool checkPrgTrace(string prgTraceFile);
//Checks to make sure Page Algorithm is fifo, lru, or clock
bool checkPageAlg(string pageAlg);
//makes sure page style is either demand or prepaging
bool checkPageStyle(string pageStyle);
//Checks to make sure page size passed is 1, 2, 4, 8, or 16
bool checkPageSize(long int pageSize);
 
int main(int argumentCount, char *argumentValues[])
{
  checkArguments(argumentCount, argumentValues);
   
  const int maxSz=10;
  const int memSz=512;
   
  string prgListFile=argVals[1];
  string prgTraceFile=argVals[2];
  string pageAlg=argVals[3];
  string pageStyle=argVals[4];
  int pageSz=atoi(argVals[5]);
   
  vector<int> sysPageTable[maxSz];
  vector<int> residentTime;
  vector<int> sysMem;
   
  bool inMemory=0;
  int pageFaultCnt=0;
  int trackVal=0;
  int clockTracker=0;
  int pageName=0;
  int parsePrgName=0;
  int parsePrgSz=0;
  int numPages=0;
  int memAlloc=0;
  int activePrg=0;
  int requestLoc=0;
  int pageLoc=0;
  int prevPage=0;
  ifstream parseFile;
   
  parseFile.open(prgListFile.c_str());//Opens Program List
  if(parseFile.fail())
  {
    cout << "Terminating the program due to missing file" << endl;
    parseFile.close();
    exit(EXIT_FAILURE);
  }
  else //Reads in Program List if it exists
  {
    pageName=0;
    while(!parseFile.eof())
    {
      parseFile >> parsePrgName;
      parseFile >> parsePrgSz;
      numPages=static_cast<int>(parsePrgSz/pageSz);
      for(int i=0; i<numPages; i++)
      {
        sysPageTable[parseProgramName].push_back(pageName);
        pageName++;
      }
    }
    parseFile.close();
  }
   
    memAlloc=static_cast<int>(ceil(memSz/pageSz));
     
  if(pageAlg=="fifo"||pageAlg=="lru")
  {
    for(int i=0; i<memAlloc; i++)
      residentTime.push_back(0);
    for(int i=0; i<maxSz; i++)
      for(int j=0; j<static_cast<int>(floor(memAlloc/maxSz)); j++)
        sysMem.push_back(sysPageTable[i][j]);
  }
  else
  {
    for(int i=0; i<memAlloc; i++)
      residentTime.push_back(1);
    for(int i=0; i<maxSize; i++)
      for(int j=0; j<static_cast<int>(floor(memAlloc/maxSz)); j++)
        sysMem.push_back(sysPageTable[i][j]);
  }
   
  parseFile.open(prgTraceFile.c_str());
  if(parseFile.fail())
  {
    cout << "Terminating the program due to missing file" << endl;
    parseFile.close();
    exit(EXIT_FAILURE);
  }
  else if(pageAlg=="fifo")
  {
    parseFile >> activePrg;
    parseFile >> requestLoc;
    pageLoc=static_cast<int>(ceil(requestLoc/pageSz));
    while(!parseFile.eof())
    {
      inMem=false;
      for(int i=0; i<static_cast<int>(sysMem.size()); i++)
      {
        if(sysMem[i]==sysPageTable[activePrg][pageLoc])
          inMem=true;
        if(inMem)
          break;
      }
      if(!inMem)
      {
        pageFaultCnt++;
        if(static_cast<int>(sysMem.size())<memAlloc)
          sysMem.push_back(sysPageTable[activePrg][pageLoc]);
        else
        {
          previousPage=0;
          for(int i=1; i<static_cast<int>(sysMem.size()); i++)
            if(residentTime[i]<residentTime[prevPage])
              prevPage=i;
          sysMem[prevPage]=sysPageTable[activePrg][pageLoc];
          residentTime[prevPage]=trackVal;
          if(pageStyle=="prepaging")
          {
            pageLoc++;
            prevPage++;
            if(prevPage==static_cast<int>(systemMemory.size()))
              prevPage=0;
            if(pageLoc==static_cast<int>(sysPageTable[activePrg].size()))
              pageLoc=0;
            sysMemory[prevPage]=sysPageTable[activePrg][pageLoc];
            residentTime[prevPage]=trackVal;
          }
        }
      }
      trackVal++;
      parseFile >> activePrg;
      parseFile >> requestLoc;
      pageLocation=static_cast<int>(ceil(requestLoc/pageSz));
    }
  }
  else if(pageAlgorithm=="lru")
  {
    parseFile >> activePrg;
    parseFile >> requestLoc;
    pageLoc=static_cast<int>(ceil(requestLoc/pageSz));
    trackValue=0;
    int count=0;
    while(!parseFile.eof())
    {
      inMem=false;
      for(count=0; count<static_cast<int>(sysMem.size()); count++)
      {
        if(sysMem[count]==sysPageTable[activePrg][pageLoc])
          inMem=true;
        if(inMem)
          break;
      }
      if(!inMem)
      {
        pageFaultCnt++;
        if(static_cast<int>(systemMemory.size())<memoryAllocation)
          systemMemory.push_back(systemPageTable[activeProgram][pageLocation]);
        else
        {
          previousPage=0;
          for(int i=1; i<static_cast<int>(systemMemory.size()); i++)
            if(residentTime[i]<residentTime[previousPage])
              previousPage=i;
          systemMemory[previousPage]=systemPageTable[activeProgram][pageLocation];
          residentTime[previousPage]=trackValue;
          if(pageStyle=="prepaging")
          {
            pageLocation++;
            previousPage++;
            if(previousPage==static_cast<int>(systemMemory.size()))
              previousPage=0;
            if(pageLocation==static_cast<int>(systemPageTable[activeProgram].size()))
              pageLocation=0;
            systemMemory[previousPage]=systemPageTable[activeProgram][pageLocation];
            residentTime[previousPage]=trackValue;
          }
        }
      }
      else if(inMemory)
        residentTime[count]=trackValue;
      trackValue++;
      parseFile >> activeProgram;
      parseFile >> requestLocation;
      pageLocation=static_cast<int>(ceil(requestLocation/pageSize));
    }
  }
  else
  {
    parseFile >> activeProgram;
    parseFile >> requestLocation;
    pageLocation=static_cast<int>(ceil(requestLocation/pageSize));
    clockTracker=0;
    int count=0;
    while(!parseFile.eof())
    {
      inMemory=false;
      for(count=0; count<static_cast<int>(systemMemory.size()); count++)
      {
        if(systemMemory[count]==systemPageTable[activeProgram][pageLocation])
          inMemory=true;
        if(inMemory)
          break;
      }
      if(!inMemory)
      {
        pageFaultCount++;
        if(static_cast<int>(systemMemory.size())<memoryAllocation)
          systemMemory.push_back(systemPageTable[activeProgram][pageLocation]);
        else
        {
          while(residentTime[clockTracker]==1)
          {
            residentTime[clockTracker]=0;
            clockTracker++;
            if(clockTracker==static_cast<int>(residentTime.size()))
              clockTracker=0;
          }
          systemMemory[clockTracker]=systemPageTable[activeProgram][pageLocation];
          residentTime[clockTracker]=1;
          if(pageStyle=="prepaging")
          {
            pageLocation++;
            clockTracker++;
            if(clockTracker==static_cast<int>(systemMemory.size()))
              clockTracker=0;
            if(pageLocation==static_cast<int>(systemPageTable[activeProgram].size()))
              pageLocation=0;
            systemMemory[clockTracker]=systemPageTable[activeProgram][pageLocation];
            residentTime[clockTracker]=1;
          }
        }
      }
      else if(inMemory)
        residentTime[count]=1;
      parseFile >> activeProgram;
      parseFile >> requestLocation;
      pageLocation=static_cast<int>(ceil(requestLocation/pageSize));
    }
  }
  parseFile.close();
   
  cout << "/**************************************************" << endl;
  cout << "Page Size: " << pageSize << endl;
  cout << "Replacement Algorithm: ";
  if(pageAlgorithm=="lru")
    cout << "Least Recently Used" << endl;
  else if(pageAlgorithm=="fifo")
    cout << "First In-First Out" << endl;
  else
    cout << "Clock Based Policy" << endl;
  cout << "Paging Style: ";
  if(pageStyle=="prepaging")
    cout << "Prepaging" << endl;
  else
    cout << "Demand Paging" << endl;
  cout << "Total Page faults: " << pageFaultCount << endl;
  cout << "/**************************************************" << endl;
   
  return 0;
}
 
void checkArguments(int argumentCount, char *argumentValues[])
{
  if(argumentCount!=6){
    cout << "Arguments needed are programList programTrace pageSize pageAlgorithm pageStyle " << endl;
    exit(1);
  }
  else if(!checkProgramList(argumentValues[1])||!checkProgramTrace(argumentValues[2])
          ||!checkPageAlgorithm(argumentValues[3])||!checkPageStyle(argumentValues[4])
          ||!checkPageSize(atoi(argumentValues[5])))
    exit(1);
  return;
}
 
bool checkProgramList(string programListFile)
{
  ifstream listFile;
  listFile.open(programListFile.c_str());
  if(listFile.fail())
  {
    cout << "Can't open " << programListFile << endl;
    listFile.close();
    return false;
  }
  else
  {
    listFile.close();
    return true;
  }
}
 
bool checkProgramTrace(string programTraceFile)
{
  ifstream traceFile;
  traceFile.open(programTraceFile.c_str());
  if(traceFile.fail())
  {
    cout << "Can't open " << programTraceFile << endl;
    traceFile.close();
    return false;
  }
  else
  {
    traceFile.close();
    return true;
  }
}
 
bool checkPageAlgorithm(string pageAlgorithm)
{
  if(pageAlgorithm=="fifo"||pageAlgorithm=="lru"||pageAlgorithm=="clock")
    return true;
  else
  {
    cout << "Valid Page Algorithms are fifo, lru, clock" << endl;
    return false;
  }
}
 
bool checkPageStyle(string pageStyle)
{
  if(pageStyle=="demand"||pageStyle=="prepaging")
    return true;
  else
  {
    cout << "Valid Paging Styles are demand, prepaging" << endl;
    return false;
  }
}
 
bool checkPageSize(long int pageSize)
{
  if(pageSize==1||pageSize==2||pageSize==4||pageSize==8||pageSize==16)
    return true;
  else
  {
    cout << "Valid Page Sizes are 1, 2, 4, 8, 16" << endl;
    return false;
  }
}