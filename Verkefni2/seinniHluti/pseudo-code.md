1. Setjum upphaflega ástand allra mótoranna sem "Stoppað".

2. Á meðan fjarstýringin er virk og neyðar-hnappurinn er ekki ýttur á:
    - Ef vinstri joysticks (Axis3) er hreyftur fram:
        - Hreyfum vinstri mótorinn fram áfram.
    - Ef vinstri joysticks (Axis3) er hreyftur afturábak:
        - Hreyfum vinstri mótorinn aftur á bak.
    - Ef hægri joysticks (Axis2) er hreyftur fram:
        - Hreyfum hægri mótorinn fram áfram.
    - Ef hægri joysticks (Axis2) er hreyftur afturábak:
        - Hreyfum hægri mótorinn aftur á bak.
    - Ef takka L1 (Vinstri Skjöldur) er ýtt á:
        - Byrjum að lyfta ArmMotor.
    - Ef takka L1 er losaður:
        - Stöðvum ArmMotor.
    - Ef takka L2 (Vinstri Tröppur) er ýtt á:
        - Byrjum að lækkar ArmMotor.
    - Ef takka L2 er losaður:
        - Stöðvum ArmMotor.
    - Ef takka R1 (Hægri Skjöldur) er ýtt á:
        - Opnum ClawMotor.
    - Ef takka R1 er losaður:
        - Stöðvum ClawMotor.
    - Ef takka R2 (Hægri Tröppur) er ýtt á:
        - Lokum ClawMotor.
    - Ef takka R2 er losaður:
        - Stöðvum ClawMotor.
    - Ef einhver takki á fjarstýringu er ýtt á:
        - Stöðvum allar mótorarnar.

3. Loka While-lúppu
