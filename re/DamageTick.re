open BsReactNative;

let component = ReasonReact.statelessComponent("DamageTick");

let make = (~title, ~onPress, ~isDamaged, _children) => {
  ...component,
  render: _self => {
    let bgColor = isDamaged ? "#CCCCCC" : "white";
    <TouchableWithoutFeedback onPress>
      <View
        style=Style.(
                style([
                  width(Pt(32.)),
                  height(Pt(32.)),
                  borderWidth(1.),
                  borderRadius(16.),
                  backgroundColor(bgColor),
                  margin(Pt(1.))
                ])
              )>
        <Text
          style=Style.(
                  style([
                    backgroundColor("transparent"),
                    textAlign(Center),
                    top(Pt(6.))
                  ])
                )
          value=title
        />
      </View>
    </TouchableWithoutFeedback>;
  }
};
