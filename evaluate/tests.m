%% group all video files

simple = {
'anne1',
'anne2',
'anne3',
'anne4',
'anne5',
'arjan1',
'arjan2',
'arjan3',
'arjan4',
'arjan5',
'gijs1',
'gijs2',
'gijs3',
'gijs4',
'gijs5',
'ivo1',
'ivo2',
'ivo3',
'ivo4',
'ivo5',
'jaspera1',
'jaspera2',
'jaspera3',
'jaspera4',
'jaspera5',
'peter1',
'peter2',
'peter3',
'peter4',
'peter5',
'hanne1',
'hanne2',
'hanne3',
'hanne4',
'hanne5',
'jasperb1',
'jasperb2',
'jasperb3',
'ork1',
'ork2',
'ork3',
'roberto1',
'roberto2',
'roberto3',
'xiaong1',
'xiaong2',
'xiaong3',
}

complex = {
'gosia1',
'gosia2',
'gosia3',
'hamdi1',
'hamdi2',
'hamdi3',
'michael1',
'michael2',
'michael3',
}

complex_poster = {
'bas1',
'bas2',
'bas3',
'koen1',
'koen2',
'koen3',
'sil1',
'sil2',
'sil3',
'victoria1',
'victoria2',
'victoria3',
}

impossible = {
'chu1',
'chu2',
'chu3',
'stratos1',
'stratos2',
'stratos3',
}

%%
for s = simple
    find(ismember(sets, s)==1)
end