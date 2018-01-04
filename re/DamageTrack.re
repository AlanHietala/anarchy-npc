open BsReactNative;

type state = {
  damage: int,
  buttons: list(list(int))
};

type action =
  | SelectDamage(int);

let component = ReasonReact.reducerComponent("DamageTrack");

let make = (~name, _children) => {
  ...component,
  initialState: () => {
    damage: 0,
    buttons: [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]]
  },
  reducer: (action, state) =>
    switch action {
    | SelectDamage(damage) => ReasonReact.Update({...state, damage})
    },
  render: self => {
    let press = damage => self.reduce(_event => SelectDamage(damage));
    let damaged = damage => self.state.damage >= damage;
    let buttonViews =
      self.state.buttons
      |> List.map(buttonRow => {
           let rowTicks =
             buttonRow
             |> List.map(damage =>
                  <DamageTick
                    key=(string_of_int(damage))
                    title=(string_of_int(damage))
                    onPress=(press(damage))
                    isDamaged=(damaged(damage))
                  />
                )
             |> Array.of_list;
           <View style=Style.(style([flexDirection(Row), flexWrap(Wrap)]))>
             (ReasonReact.arrayToElement(rowTicks))
           </View>;
         })
      |> Array.of_list;
    <View style=Style.(style([width(Pt(105.))]))>
      <Text value=name />
      <Button title="Reset" onPress=(press(0)) />
      <View style=Style.(style([flexWrap(Wrap)]))>
        (ReasonReact.arrayToElement(buttonViews))
      </View>
    </View>;
  }
};
