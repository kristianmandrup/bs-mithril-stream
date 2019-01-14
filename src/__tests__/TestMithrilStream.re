open MithrilStream;
open Jest;
open ExpectJs;

describe("MithrilStream", () => {
  test("#stream", () =>
    expect(() =>
      stream(~value=4)
    ) |> not |> toThrow
  );

  test("#combine", () =>
    expect(() =>
      combine(x => x + 4, [|1|])
    ) |> not |> toThrow
  );

/* instance */

  /* test("#end", () =>
       expect(() =>
         stream().end
       ) |> not |> toThrow
     ); */
  /* test("#map", () =>
       expect(() =>
         stream().map(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#of", () =>
       expect(() =>
         stream().of(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#ap", () =>
        expect(() =>
          stream().ap(x => x)
        ) |> not |> toThrow
      );
     */

/* static */

  /* test("#scan", () =>
       expect(() =>
         scan(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#merge", () =>
       expect(() =>
         merge([|stream()|])
       ) |> not |> toThrow
     ); */
  /* test("#scanMerge", () =>
       expect(() => {
         let pairs = [|stream()|];
         let acc = [];
         scanMerge(pairs, acc);
       }) |> not |> toThrow
     ); */
  /* test("#lift", () =>
       expect(() => {
         let streams = [|stream()|];
         let lifterFn = (x) => x;
         lift(lifterFn, streams);
       }) |> not |> toThrow
     ); */
  /* test("#lifter", () =>
       expect(() => {
         let streams = [|stream()|];
         lifter(streams);
       }) |> not |> toThrow
     ); */


});