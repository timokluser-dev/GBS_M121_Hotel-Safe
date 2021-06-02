# Lernjournal 05.05.2021

## Tätigkeiten

- Alle Projekte angeschaut und uns für eines entschieden
- Brainstorming zur Projektidee gemacht und Notizen im MS Whiteboard festgehalten
- GitHub Projekt erstellt und für alle Projekt beteiligten zur verfügung gestellt
- Nach zusätzlichen Bauteile Recherchiert
- Prinzipskizze mit draw.io angefertigt
- DevOps Strategie entworfen

## Was habe ich gelernt

- Weitere Erfahrungen mir draw.io gesammelt

## Positive Erfahrungen

- Spannendes Projekt mit guten Erweiterungen erhalten
- Gutes Team für das Projekt
- Grosser Vorschritt schon nach einem Tag

## Negative Erfahrungen

- _Keine Negativen Erfahrungen_

## Welches sind die nächsten Arbeitsschritte

- Genauere Planung
- Zustandsdiagramm anfertigen
- Entwurf Prototyp
- Einzelne Komponenten testen mittels Beispiel-Programmen

<br>
<br>

# Lernjournal 12.05.2021

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
- Applikationssicherheit durch sperren im Backend
- Wie und wo recherchiere ich nach Arduino Komponenten

## Positive Erfahrungen

- API funktioniert soweit
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

# Lernjournal 19.05.2021

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
- Komponenten anschliessen und die Header FIles mit funktionalität versehen
- _Auf die restlichen Komponenten (WiFi Modul, Schieberegister) warten_

<br>
<br>

# Lernjournal 26.05.2021

## Tätigkeiten

- Bug mit dem Header Include behoben
- WiFi Modul (ESP8266) in Betrieb genommen (Initial Konfiguration)
- Code erweitern mit WiFi Verbindung
- Versucht einen Http Request zu programmieren, ohne Erfolg

## Was habe ich gelernt

- Wenn mit mehreren Files gearbeitet wird, sollte eine `src/` Ordern erstellt werden, denn ansonsten kommt es zu Problemen mit dem Arduino compiler. (Genanntes Include Bug von letzter Woche)
- Manchmal kommt es zu Caching Problemen beim Arduino wenn mir verschiedenen Libraries gearbeitet wird

## Positive Erfahrungen

- Die Verkablung vom WiFi Modul ist abgeschlossen und funktioniert
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

# Lernjournal 02.06.2021

## Tätigkeiten

- Program refactoring, um Speicherplatz zu sparen
- Problem mit dem Mikrocontroller versucht zu beheben

## Was habe ich gelernt

- Zuvor ausgesuchte WiFi Library scheint nicht zu funktionieren, da diese voraussetzt, dass man das Program vom ESP8266 aus steuern lässt
- Das Theorietisches absetzten von API calls über die Serielle CLI vom Mikrocontroller (WiFi Module)

## Positive Erfahrungen

- Program konnte um 10% in der Grösse verkleinert werden

## Negative Erfahrungen

- Der Serielle Output vom Mikrocontroller kann komischer Weise nicht vom Arduino ausgelesen werden
- Das Problem mit dem WiFi wirkt sich negativ auf den Fortschritt mit dem Projekt aus

## Welches sind die nächsten Arbeitsschritte

- Weiterhin am Problem mit dem WiFi Modul arbeiten
- Letzter Schliff
- Dokumente überprüfgen und ggf. noch anpassen
