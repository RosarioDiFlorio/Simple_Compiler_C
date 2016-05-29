jflex c.jflex
java -jar java-cup-11a.jar -interface -parser Parser c.cup
javac -cp java-cup-11a.jar *.java
