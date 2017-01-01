import urllib
import requests
from bs4 import BeautifulSoup

def getLinks(wavQuery):

	mainUrl = "http://www.villagegeek.com/html/"
	requestsObject = requests.get(mainUrl + wavQuery)
	data = requestsObject.text
	soup = BeautifulSoup(data)

	wavFiles = []
	links = []
	wavs = []
	seed = 'http://www.villagegeek.com'

	for link in soup.find_all('a'):
		links.append(link.get('href'))

	for link in links:
		if str(link)[-4:] == '.wav':
			wavFiles.append(link)

	for link in wavFiles:
		ascciRepresentation = str(link)
		query = ascciRepresentation.find('/')
		identifier = seed + ascciRepresentation[query:]
		wavs.append(identifier)

	return wavs

def getAllFilesAsData():

	links = []
	queries = ['wavfiles1.htm', 'wavfiles2.htm', 'wavfiles3.htm', '/biblioteca/wavfiles4.htm']
	for query in queries:
		data = getLinks(query)
		links.extend(data)
	return links

def downloadFiles(listOfData):

	for link in listOfData:
		namePos = link.rindex('/')
		name = link[namePos + 1:]
		urllib.urlretrieve(link, name)


def main():

	links = getAllFilesAsData()
	downloadFiles(links)

main()
