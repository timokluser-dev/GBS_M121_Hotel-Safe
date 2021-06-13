Timo Kluser

# Arbeitsjournal 05.05.2021

## Tätigkeiten

- Alle Projekte angeschaut und uns für eines entschieden
- Brainstorming zur Projektidee gemacht und Notizen im MS Whiteboard festgehalten
- GitHub Projekt erstellt und für alle Projekt beteiligten zur Verfügung gestellt
- Nach zusätzlichen Bauteilen recherchiert
- Prinzipskizze mit draw.io angefertigt
- DevOps Strategie entworfen

## Was habe ich gelernt

- Weitere Erfahrungen mir draw.io gesammelt

## Positive Erfahrungen

- Spannendes Projekt mit guten Erweiterungen erhalten
- Gutes Team für das Projekt
- Grosser Fortschritt schon nach einem Tag

## Negative Erfahrungen

- _Keine negativen Erfahrungen_

## Welches sind die nächsten Arbeitsschritte

- Genauere Planung
- Zustandsdiagramm anfertigen
- Entwurf Prototyp
- Einzelne Komponenten testen mittels Beispiel-Programmen

<br>
<br>

# Arbeitsjournal 12.05.2021

## Tätigkeiten

- Genauere Planung besprochen und festgehalten
- Erweiterungsstufen mündlich besprochen
- Zustandsdiagramm erstellt und im Team reviewed
- REST API mit .NET 5 entwickelt
- REST API getestet
- Komponentenliste konkretisiert

## Was habe ich gelernt

- [OData](https://www.odata.org) Komponente für ASP.NET Web API
- Sicherung einer API mit API Keys
- Applikationssicherheit durch Sperren im Backend
- Wie und wo recherchiere ich nach Arduino Komponenten

## Positive Erfahrungen

- API funktioniert so weit
- Das Zustandsdiagramm ist meiner Meinung nach sehr schön geworden
- Aktueller Projektvorschritt ist auf Kurs

## Negative Erfahrungen

- Die Zeit in der Lektion vergeht sehr schnell

## Welches sind die nächsten Arbeitsschritte

- Einzelne Komponenten testen mittels Beispiel-Programmen (Komponenten sind bestellt)
- Gegebenenfalls Zustandsdiagramm von API
- Überlegung: Wann soll der PIN gelöscht oder blockiert werden?

<br>
<br>

# Arbeitsjournal 19.05.2021

## Tätigkeiten

- Besprechung bezüglich dem Master PIN und der Fail2Ban Funktion
- Erster Entwurf vom Code für den Arduino erstellt
- Header Files zur Modularisierung erstellt
- Funktionen in den Header Files programmiert und testhalber statischer Inhalt zurückgegeben

## Was habe ich gelernt

- Header Files zur Vereinheitlichung mit dem Arduino
- Programm [Fritzing](http://www.fritzing.org/) zum Erstellen von Arduino Schaltpläne

## Positive Erfahrungen

- Numpad ist angekommen und konnte schon getestet werden
- Mein Konzept mit dem Auslagern von Funktionen in Headerfiles scheint mehrheitlich zu funktionieren

## Negative Erfahrungen

- Es scheint ein Problem mit dem Inkludieren von speziellen Header Files zu geben

## Welches sind die nächsten Arbeitsschritte

- Bug mit dem Header File include beheben
- Komponenten anschliessen und die Header Files mit Funktionalität versehen
- _Auf die restlichen Komponenten (WiFi Modul, Schieberegister) warten_

<br>
<br>

# Arbeitsjournal 26.05.2021

## Tätigkeiten

- Bug mit dem Header Include behoben
- WiFi Modul (ESP8266) in Betrieb genommen (Initial Konfiguration)
- Code erweitern mit WiFi Verbindung
- Versucht einen Http Request zu programmieren, ohne Erfolg

## Was habe ich gelernt

- Wenn mit mehreren Files gearbeitet wird, sollte eine `src/` Ordern erstellt werden, denn ansonsten kommt es zu Problemen mit dem Arduino Compiler. (Genanntes Include Bug von letzter Woche)
- Manchmal kommt es zu Caching Problemen beim Arduino, wenn mit verschiedenen Libraries gearbeitet wird

## Positive Erfahrungen

- Die Verkabelung des WiFi Moduls ist abgeschlossen und funktioniert
- Gutes Arbeitstempo

## Negative Erfahrungen

- Bug mit der WiFi Library für das Wireless Modul, Reference zur Class wird nicht gefunden
- Maximale Programmgrösse beim Arduino ist schnell erreicht

## Welches sind die nächsten Arbeitsschritte

- WiFi Library Bug begehen
- Programm Size optimieren
- API Calls absetzen mit dem Arduino

<br>
<br>

# Arbeitsjournal 02.06.2021

## Tätigkeiten

- Programm Refactoring, um Speicherplatz zu sparen
- Problem mit dem Mikrocontroller versucht zu beheben

## Was habe ich gelernt

- Zuvor ausgesuchte WiFi Library scheint nicht zu funktionieren, da diese voraussetzt, dass man das Programm vom ESP8266 aus steuern lässt
- Das Theorietisches absetzten von API-Calls über die Serielle CLI vom Mikrocontroller (WiFi Module)

## Positive Erfahrungen

- Programm konnte um 10% in der Grösse verkleinert werden

## Negative Erfahrungen

- Der Serielle Output vom Mikrocontroller kann komischer Weise nicht vom Arduino ausgelesen werden
- Das Problem mit dem WiFi wirkt sich negativ auf den Fortschritt mit dem Projekt aus

## Welches sind die nächsten Arbeitsschritte

- Weiterhin am Problem mit dem WiFi Modul arbeiten
- Letzter Schliff
- Dokumente überprüfen und ggf. noch anpassen

<br>
<br>

# Arbeitsjournal 02.06.2021

## Tätigkeiten

- Erneutes Programm Refactoring, um Speicherplatz zu sparen
- WiFi Modul Ansteuerung mittels Serieller Schnittstelle
- Mit Herr Keller die WiFi Problematik besprochen
- Dokumentation geschrieben
- Projekt Dokumente nochmals kontrolliert

## Was habe ich gelernt

- Auch mittels Serieller Schnittstelle zum WiFi Modul können keine Responses empfangen werden, da der Mikrochip zu wenig Ressourcen hat
- Einfache HTTP Aufrufe ohne Response hätten hingegen funktioniert. Unsere API hat aber leider Responses, welche im Programm nötig sind
- Das es viele verschiedene Ausführungen vom ESP8266 gibt und auf vielen verschiedenen Webseiten was anderes steht. Sehr verwirrend.

## Positive Erfahrungen

- Austausch mit Herr Keller konnte noch diverse Erkenntnisse bestätigen

## Negative Erfahrungen

- Die API-Rückgabe kann nicht gelesen werden, was unser Konzept nicht möglich macht
- Wahrscheinlich müsste ein neuer Arduino Uno WiFi angeschafft werden, um unser Projekt noch zu realisieren. Leider nicht möglich Aufgrund der fehlenden Zeit.
- Das Problem mit dem WiFi wirkt sich negativ auf den Fortschritt mit dem Projekt aus
- Das Problem mit dem ESP8266 hat sich negativ auf den Projektstand ausgewirkt.

## Welches sind die nächsten Arbeitsschritte

- Projekt für Abgabe fertig machen

<br>
<br>

# Persönliche Reflexion

Das Projekt hat trotz Frustration und Rückschlägen einen Mehrwert gebracht. Von Anfang an war mir klar, dass das eine Challenge wird mit der externen API und einer WiFi Schnittstelle für den Arduino. Ich wollte diese Challenge annehmen und mich mal daran Probieren.

## Projektverlauf

Das Projekt ist am Anfang sehr gut verlaufen. Wir waren im Zeitplan und konnten schnelle Fortschritte verzeichnen. Das Problem kam dann mit dem WiFi Modul (ESP8226). Online gab es viele verschiedene Anleitungen dazu, jedoch war oft nicht klar welcher Typ vom ESP8226 verwendet wird. Auf dem Titelbild war zum Beispiel den ESP8266-U1, welchen wir hatten, und im Artikel wird dann mit der Library gearbeitet, die nur für den Standard ESP8226 funktional ist. Da wir zu zweit waren konnte Damian schon mit der Dokumentation beginnen und so wieder ein wenig Zeit gutmachen. Zum Schluss mussten wir uns aber mit dem Problem geschlagen geben und uns auf den Projektabschluss kümmern.

## Lernfortschritt

In diesem Projekt konnte ich jede Menge lernen. Die Grundlagen vom Unterricht mit den verschiedenen Diagrammen konnte man besten nochmals üben. Da die Struktur der Diagramme bekannt war, konnte man sich ganz auf das Konzept und den Prototypen kümmern. Zwischendurch hatte ich wieder ein paar Probleme, wie zum Beispiel das Problem mit den Header Dateien. Für zukünftige Projekte sollte man immer einen `src/` Folder erstellen und darin die Header Dateien lagern. Das `.ino` File sollte in der Project-Root sein. Die [Arduino Community](https://forum.arduino.cc/) war mir eine grosse Hilfe beim Beseitigen von sämtlichen Problemen. In Bezug auf die API konnte ich die `Api-Key` Authentifizierung kennenlernen. Sie ist kompakt und sprengt den HTTP Header nicht all zu gross, wie es ein JWT tun würde. Zum Schluss kam ich dann auf den Genuss, was es heisst zu wenig Speicherplatz auf dem Board zu haben. Hierbei habe ich ein Arduino Post zur Hilfe genommen. Kaum vorstellbar, dass man früher noch limitiert auch Speicher war und heute kaum mehr darauf achtet. Trotzdem eine interessante Erfahrung.

## Endprodukt

Leider lässt sich vom Endprodukt nicht so viel sehen. Das Programm konnte aufgrund fehlenden Speicherplatzes nicht mehr auf den Arduino übertragen werden und das WiFi Modul hat auch nicht zu 100% funktioniert. Der Code wurde jedoch Stück für Stück getestet und ist valid. Wenn das Konzept funktioniert hätte, wäre es ein super Produkt gewesen. Nichtsdestotrotz finde ich aber, dass uns das Endprodukt trotzdem gelungen ist. Wir haben viel Zeit investiert und haben nicht einfach aufgegeben. Es brächte nicht mehr viel und das Produkt wäre vollumfänglich nutzbar. Leider haben wir die Zeit nicht mehr, was auch ein bisschen Schade ist.
