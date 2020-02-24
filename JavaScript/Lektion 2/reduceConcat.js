/* Opgave, der skal få et array af arrays lavet om til ét array */

let arrays = [[1, 2, 3], [4, 5], [6]];
let reducedArray = arrays.reduce((a,b) => (a.concat(b)));
console.log(reducedArray);

/* a og b er arrays i denne sammenhæng og ikke elementerne inde i arrays'ne.
   første gang tager reduce a værende et tomt array og b værende [1, 2, 3].
   den bruger så concat på disse to (eksemplet sagde a+b, men vi har skrevet
   en anden funktion, som concat'er de to arrays).
   Dette betyder, at det tomme array bliver sat sammen med [1, 2, 3]. Den
   kører videre gennem arrayet, så nu er [1, 2, 3] vores a, og næste element
   [4, 5] er vores b. Nu skal disse concatineres, så vi får [1, 2, 3, 4, 5].
   Repeat ind til færdig, så vi får [1, 2, 3, 4, 5, 6].