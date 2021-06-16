using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RespawnScript : MonoBehaviour
{
    public Transform player;
    public Transform Respawnpoint;

    private void OnCollisionEnter(Collision other)
    {
        player.transform.position = Respawnpoint.transform.position;
    }
}
