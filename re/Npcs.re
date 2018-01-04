open BsReactNative;

type state = {
  npcs: list(string),
  inputText: string
};

type action =
  | AddNpc(string)
  | RemoveNpc(string)
  | UpdateText(string);

let component = ReasonReact.reducerComponent("Npcs");

let make = _children => {
  ...component,
  initialState: () => {npcs: [], inputText: ""},
  reducer: (action, state) =>
    switch action {
    | RemoveNpc(removeName) =>
      ReasonReact.Update({
        ...state,
        npcs: List.filter(name => removeName != name, state.npcs)
      })
    | AddNpc(name) =>
      ReasonReact.Update({
        ...state,
        npcs: [name, ...state.npcs],
        inputText: ""
      })
    | UpdateText(inputText) => ReasonReact.Update({...state, inputText})
    },
  render: self => {
    let removeNpc = name => self.reduce(_event => RemoveNpc(name));
    let npcs =
      self.state.npcs
      |> List.map(name => <Npc name removeNpc=(removeNpc(name)) />)
      |> Array.of_list;
    <View style=Style.(style([flex(1.), marginTop(Pt(40.))]))>
      (ReasonReact.arrayToElement(npcs))
      <Text value="Add Goon" />
      <TextInput
        value=self.state.inputText
        style=Style.(style([borderWidth(1.)]))
        onChangeText=(self.reduce(text => UpdateText(text)))
      />
      <Button
        title="add"
        onPress=(self.reduce(_event => AddNpc(self.state.inputText)))
      />
    </View>;
  }
};
