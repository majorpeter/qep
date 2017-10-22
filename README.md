# Quadrature Encoder interface/driver

## Desription

An incremental rotary encoder provides cyclical outputs (only) when the encoder is rotated. They can be either mechanical, optical or magnetic. The mechanical type requires debouncing and is typically used as digital potentiometers on equipment including consumer devices. Most modern home and car stereos use mechanical rotary encoders for volume control. Due to the fact the mechanical switches require debouncing, the mechanical type are limited in the rotational speeds they can handle. The incremental rotary encoder is the most widely used of all rotary encoders due to its low cost and ability to provide signals that can be easily interpreted to provide motion related information such as velocity.

The fact that incremental encoders use only two sensors does not compromise their resolution. One can find in the market incremental encoders with up to 10,000 counts per revolution, or more.

There can be an optional third output: reference or "index", which happens once every turn. This is used when there is the need of an absolute reference, such as positioning systems. The index output is usually labeled Z.

The optical type is used when higher speeds are encountered or a higher degree of precision is required.

Incremental encoders are used to track motion and can be used to determine position and velocity. This can be either linear or rotary motion. Because the direction can be determined, very accurate measurements can be made.

They employ two outputs called A & B, which are called quadrature outputs, as they are 90 degrees out of phase.

The state diagram:

| Phase |  A |  B |
|-------|----|----|
| 1     | 0  | 0  |
| 2     | 0  | 1  |
| 3     | 1  | 1  |
| 4     | 1  | 0  |

[Source: Wikipedia/Rotary encoder - Incremental rotary encoder](https://en.wikipedia.org/wiki/Rotary_encoder#Incremental_rotary_encoder)
