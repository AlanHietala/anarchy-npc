open BsReactNative;

let component = ReasonReact.statelessComponent("Npc");

let make = (~name, ~removeNpc, _children) => {
  ...component,
  render: _self =>
    <View style=Style.(style([marginTop(Pt(20.)), width(Pct(100.))]))>
      <View style=Style.(style([flexDirection(Row)]))>
        <Text
          style=Style.(
                  style([
                    fontSize(Float(20.)),
                    marginLeft(Pt(10.)),
                    fontSize(Float(30.))
                  ])
                )
          value=name
        />
        <Button onPress=removeNpc title="remove" />
      </View>
      <View
        style=Style.(style([flexDirection(Row), justifyContent(SpaceAround)]))>
        <DamageTrack name="Armor" />
        <DamageTrack name="Physical" />
        <DamageTrack name="Stun" />
      </View>
    </View>
};
