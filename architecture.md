## Menu
- feed the list of covid +ve people
    - go to `peopleArray`'s indices and set their `status` to `1`
    - set these people's `primaryContactList`'s each entry to have `riskFactor` = 2
    - set these people's `secondaryContactList`'s each entry to have `riskFactor` = 1
    - set these people's `quarantineEndsOn` to `currentDate + 14`
- increment day
    - do `currentDay++`
- make a person travel
    - make a new menu for this asking which person, and his destination, then present him top 3 paths and ask the user for approval
    - needs work on this
- print list of +ve people
    - itearate through the `peopleArray` and print those people's indices who have `status == 1`
- print list of who all is in which city
    - interate through `cityArray` and print their residents
- print all info about a specific person
    - go the specific index in `peopleArray` and print all its contents
- At city `S` who all are primary contacts of a covid +ve person
    - go to that index in `cityArray` and print those people who have `riskFactor == 2` as "primary contacts of a covid +ve patient"
    - go to that index in `cityArray` and print those people who have `riskFactor == 1` as "secondary contacts of a covid patient"
    - (It might not be the case that all people in the city `S` will be primary contacts of a covid positive person because: consider a case when a new person comes in who never interacted with the coid positive person. in that case that new person will be the secondary contact of that person)

## Structs and info
### `struct person`
- `int location` (curreny city of residence)
- `int covidStatus` (0 for OK, 1 for +ve)
- list of his primary contacts ==> this list will be of a struct containing `struct person` and the absolute date of meeting `int when_they_met`
- list of his secondary contacts ==> this list will be of a struct containing `struct person` and the absolte date of meeting`int whenTheyMmet`
- `int quarantineEndsOn`: the absolute date on which their quarantine will end.
- `int riskFactor` = {0,1,2}: (yes we do need this, read `struct city` subheading) 
    - reason: in case a person X tests positive, then a person P who came into contact with X will be his primary contact, so P's risk factor will be 2
    - X's secondary contacts will have risk_factor 1
    - those people will have a risk factor of 0 if none of their primary or secondary conacts have gotten covid yet

### `struct city`
- list of all people
- list of +ve people
- list of people whose `riskFactor` ==1 are counted as primary contacts of an infectee
- list of people who have `riskFactor` ==2 are counted as secondary contacts of an infectee
- int `dangerValue`
- in case adj list representation method is chosen: list of cities it connects to (linked list ints (becuase cities are identified by number))
    - using this way the array of `struct city` is all we need to store graphs, no need for building/maintaining/updating othe storage structure. 

## Setup
- For the graph: 
    - if the algo requires adj list representation, then as described in the city struct subheading. 
    - if the algo requires edge list format then array of( tuple of (city and danger value))
- maintain an array of people to deal with people related functions

## TODO
- [ ] implemenatation team to make linked list an easily usable data structure, preferably like a template: you tell that the linked list constructor to make a linked list of what data structure. Something like `list(int) listOfInts;` or `list(person) listOfPersons;` etc.
- [ ] Graphs to be implemented as above
- [ ] `struct person`
- [ ] `struct city`
- [ ] a struct which clubs `int personId` and `whenTheyMet`, because the primary and secondary contact list will be made out of them 
- [ ] array of persons `personArray` 
- [ ] array of cities `cityArray`
- [ ] think of kth shortest path algo

## List of All variable/struct names
### Relating to person
- `struct person` : information about each person
- `int location` : tells the city number where a person is present
- `int covidStatus` : 0 for healthy, 1 for covid +ve
- `int quarantineEndsOn` : date on which person's quarantine ends
- `int riskFactor` : 2 if the person has met a covid positive person in the last 14 days, 1 if the person has met a person with `riskFactor` 1 in the last 14 days. 0 if none prevails.
- `person personArray[N]` array containing all the people
- `list primaryContactList` : list of struct of the people who met this indiviudal along with the date
- `list secondaryContactList` :  pls fill in here im tired :(

**add more variables about person here**

### Realting to city
- `struct city`: information about a city
- `int dangerValue` : danger value of a city
- `city cityArray[M]` : array containing all cities

**add more variables about city here**

### Misc variables
- `int currentDate`

## Misc
- variable nomenclature: if more variables need to be added, follow camelCase nomenclature
 


