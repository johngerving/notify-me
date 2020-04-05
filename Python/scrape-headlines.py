import bs4
from bs4 import BeautifulSoup as soup
from urllib.request import urlopen


news_url="https://news.google.com/news/rss"

Client=urlopen(news_url)
xml_page=Client.read()
Client.close()

soup_page=soup(xml_page,"xml", from_encoding="utf-8")
news_list=soup_page.findAll("title")

for n in range(len(news_list)):
  news_list[n] = news_list[n].text
print(len(max(news_list, key=len)))
# Print news title, url and publish date
f = open("scraped_titles.txt", "w")
for news in news_list:
  f.write("\"" + news + "\"," + '\n')
f.close()
